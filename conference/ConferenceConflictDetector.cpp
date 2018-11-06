/* 
 * File:   ConferenceConflictDetector.cpp
 * Author: jake.rowland
 * 
 * Created on September 25, 2018, 9:47 AM
 */

#include "ConferenceConflictDetector.h"

ConferenceConflictDetector::ConferenceConflictDetector(
        const int N, 
        const int S, 
        const int K, 
        const Dist dist,
        const ConflictSizeConstraint size) {
    if(N < 0) {
        throw std::invalid_argument(
                "ConferenceConflictDetector: N must be positive");
    }
    if(S < 0) {
        throw std::invalid_argument(
                "ConferenceConflictDetector: S must be positive");
    }
    if(K < 0) {
        throw std::invalid_argument(
                "ConferenceConflictDetector: K must be positive");
    }
    if(K > N) {
        throw std::invalid_argument(
                "ConferenceConflictDetector: K must be less than N");
    }
    
    sessions = N;
    attendees = S;
    sesPerAtte = K;    
    distribution = dist;
    conflictSize = size;
    
    setUpDistribution();
    selectConflictSize();
}

ConferenceConflictDetector::ConferenceConflictDetector(
        const ConferenceConflictParams* params) {
    sessions = params->getSessions();
    attendees = params->getAttendees();
    sesPerAtte = params->getSessionsPerAttende();
    lowerBound = params->getLowerBound();
    twoTieredTier = params->getTwoTieredTier();
    twoTieredSplit = params->getTwoTieredSplit();
    showOutput = params->getOutput();
    showOutputNewLine = params->getOutputNewLine();
    pBatchSize = params->getPBatch();
    eBatchSize = params->getEBatch();
    distribution = params->getDistribution();
    conflictSize = params->getConflictSizeConstrinat();
    
    setUpDistribution();
    selectConflictSize();
}

ConferenceConflictDetector::~ConferenceConflictDetector() {
    delete distributionGenerator;
    delete conflictHandler;
}

void ConferenceConflictDetector::generateConflicts() {
    bool shouldShow = false;
    if(showOutput > 0 ) {
        std::cout << "ConferenceConflictDetector::generateConflicts: " << 
                "Showing every " << showOutput << "th iteration" << std::endl;
        shouldShow = true;
    }
    
    conflictHandler->addConflictCount(MathUtils::pairs(sesPerAtte) * attendees);
    for(int attendee = 0; attendee < attendees; attendee++) {
        std::set<int> set = distributionGenerator->generateSessions(sesPerAtte);
        addConflictSet(set);
        
        if(shouldShow) {
            if(attendee % showOutput == 0 && attendee != 0) {
                std::cout << "." ;
            }
            if(attendee % (showOutput*showOutputNewLine) == 0 
                    && attendee != 0) {
                std::cout << std::endl;
            }
        }
        
        if(conflictHandler->isAtMaxConflicts()) {
            return;
        }
        
        // If the last attendee is reached, end the line to get messages out.
        if(shouldShow && attendee == attendees-1) {
            std::cout << std::endl;
        }
    }
}

void ConferenceConflictDetector::handleResults(std::string output) {
    FileHandler fileHandler;
    fileHandler.openFile(output);
    
    //N Output
    fileHandler.write("N", sessions);
    
    //M Output
    fileHandler.write("M", conflictHandler->getSizeOfEArray());
    
    //T Output
    fileHandler.write("T", conflictHandler->getConflictCount());
    
    //S Output
    fileHandler.write("S", attendees);
    
    //K Output
    fileHandler.write("K", sesPerAtte);
    
    //DIST Output
    switch(distribution) {
        case Dist::Uniform:
            fileHandler.write("DIST", "UNIFORM");
            break;
        case Dist::Tiered:
            fileHandler.write("DIST", "TIERED");
            break;
        case Dist::Skewed:
            fileHandler.write("DIST", "SKEWED");
            break;
        case Dist::Binomial:
            fileHandler.write("DIST", "BINOMIAL");
            break;
        default:
            fileHandler.write("DIST", "UNIFORM");
            break;
    }
    
    // Get the peArray
    int** peArray = conflictHandler->peArray();
    
    //P[] Output
    fileHandler.writeList("P", *(peArray+0), sessions, pBatchSize);
    //E[] Output
    fileHandler.writeList("E", *(peArray+1), conflictHandler->getSizeOfEArray(), 
                    eBatchSize);
    
    delete[] *(peArray+0);
    delete[] *(peArray+1);
    delete[] peArray;
    
    fileHandler.closeFile();
}

void ConferenceConflictDetector::setUpDistribution() {
    switch(distribution) {
        case Dist::Uniform:
            distributionGenerator = new UniformDistribution(
                    lowerBound, 
                    sessions);
            break;
        case Dist::Tiered:
            distributionGenerator = new TwoTieredDistribution(
                    0,
                    twoTieredTier, 
                    twoTieredSplit, 
                    sessions);
            break;
        case Dist::Skewed:
            distributionGenerator = new SkewedDistribution(
                    lowerBound, 
                    sessions);
            break;
        case Dist::Binomial:
            distributionGenerator = new BinomialDistribution(
                    lowerBound,
                    sessions);
            break;
        default:
            distributionGenerator = new UniformDistribution(
                    lowerBound,
                    sessions);
            break;
    }
}

void ConferenceConflictDetector::selectConflictSize() {
    switch(conflictSize) {
        case ConflictSizeConstraint::M:
            conflictHandler = new ConflictList(sessions);
            break;
        case ConflictSizeConstraint::N2:
            conflictHandler = new ConflictGraph(sessions);
            break;
        default:
            conflictHandler = new ConflictGraph(sessions);
    }
}

void ConferenceConflictDetector::addConflictSet(std::set<int> set) {
    for(std::set<int>::iterator first = set.begin(); 
            first != set.end(); 
            ++first) {
        for(std::set<int>::iterator second = first; 
                second != set.end(); 
                ++second) {
            if(*first != *second) {
                std::pair<int,int> pair = std::make_pair(*first, *second);
                conflictHandler->addConflict(pair);
            }
        }
    }
}