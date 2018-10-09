/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
        const ConflictSizeConstrinat size) {
    if(N < 0) {
        throw std::invalid_argument("ConferenceConflictDetector: N must be positive");
    }
    if(S < 0) {
        throw std::invalid_argument("ConferenceConflictDetector: S must be positive");
    }
    if(K < 0) {
        throw std::invalid_argument("ConferenceConflictDetector: K must be positive");
    }
    if(K > N) {
        throw std::invalid_argument("ConferenceConflictDetector: K must be less than N");
    }
    
    sessions = N;
    attendees = S;
    sesPerAtte = K;    
    distribution = dist;
    conflictSize = size;
    
    setUpDistribution();
    selectConflictSize();
    
    initalDebug();
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
    debugMode = params->getDebugMode();
    
    setUpDistribution();
    selectConflictSize();
    
    initalDebug();
}

ConferenceConflictDetector::~ConferenceConflictDetector() {
    delete distributionGenerator;
    delete conflictHandler;
}

void ConferenceConflictDetector::generateConflicts() {
        if(debugMode == 1 ) {
            std::cout << "ConferenceConflictDetector::generateConflicts: Starting" << std::endl;
        }

    bool shouldShow = false;
    if(showOutput > 0 ) {
        std::cout << "ConferenceConflictDetector::generateConflicts: Showing every " << showOutput << "th iteration" << std::endl;
        shouldShow = true;
    }
    
    conflictHandler->addConflictCount(MathUtils::pairs(sesPerAtte) * attendees);
    
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::generateConflicts: Starting to generate Attendee sets" << std::endl;
            }
    
    for(int attendee = 0; attendee < attendees; attendee++) {
        std::set<int> set = distributionGenerator->generateSessions(sesPerAtte);
        addConflictSet(set);
        
        if(shouldShow) {
            if(attendee % showOutput == 0 && attendee != 0) {
                std::cout << "." ;
            }
            if(attendee % (showOutput*showOutputNewLine) == 0 && attendee != 0) {
                std::cout << std::endl;
            }
        }
        
        if(conflictHandler->isAtMaxConflicts()) {
            if(debugMode >= 1) {
                std::cout << std::endl;
                if (debugMode >= 2 ) {
                    std::cout << "Final attendee was " << attendee << std::endl;
                }
                std::cout << "Ending early because no more combinations need to be accounted for." << std::endl;
            }
            return;
        }
        
        // If the last attendee is reached, end the line to get messages out.
        if(shouldShow && attendee == attendees-1) {
            std::cout << std::endl;
        }
    }
    
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::generateConflicts: Finished generating Attendee sets" << std::endl;
            }
        if(debugMode == 1 ) {
            std::cout << "ConferenceConflictDetector::generateConflicts: Ending" << std::endl;
        }
}

void ConferenceConflictDetector::handleResults(std::string output) {
        if(debugMode >= 1 ) {
            std::cout << "ConferenceConflictDetector::handleResults: Starting" << std::endl;
        }
    
    FileHandler fileHandler;
    fileHandler.openFile(output);
    
    //N Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing N" << std::endl;
            }
    fileHandler.write("N", sessions);
    
    //M Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing M" << std::endl;
            }
    fileHandler.write("M", conflictHandler->getSizeOfEArray());
    
    //T Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing T" << std::endl;
            }
    fileHandler.write("T", conflictHandler->getConflictCount());
    
    //S Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing S" << std::endl;
            }
    fileHandler.write("S", attendees);
    
    //K Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing K" << std::endl;
            }
    fileHandler.write("K", sesPerAtte);
    
    //DIST Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Writing DIST" << std::endl;
            }
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
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Creating the peArray" << std::endl;
                start = std::chrono::system_clock::now();
            }
    int** peArray = conflictHandler->peArray();
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Created the peArray in ";
                auto end = std::chrono::system_clock::now() - start;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration  << "ms" << std::endl;
            }
    
    //P[] Output
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Started writing P[]" << std::endl;
                start = std::chrono::system_clock::now();
            }
    fileHandler.writeList("P", *(peArray+0), sessions, pBatchSize);
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Finished writing P[] in ";
                auto end = std::chrono::system_clock::now() - start;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration  << "ms" << std::endl;
            }
    
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Started writing E[]" << std::endl;
            }
    //E[] Output
    fileHandler.writeList("E", *(peArray+1), conflictHandler->getSizeOfEArray(), eBatchSize);
            if(debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::handleResults: Finished writing E[] in ";
                auto end = std::chrono::system_clock::now() - start;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration  << "ms" << std::endl;
            }
    
    delete[] *(peArray+0);
    delete[] *(peArray+1);
    delete[] peArray;
    
    fileHandler.closeFile();
    
        if(debugMode >= 1 ) {
            std::cout << "ConferenceConflictDetector::handleResults: Ending" << std::endl;
        }
}

void ConferenceConflictDetector::setUpDistribution() {
    switch(distribution) {
        case Dist::Uniform:
            distributionGenerator = new UniformDistribution(
                    lowerBound, 
                    sessions,
                    debugMode);
            break;
        case Dist::Tiered:
            distributionGenerator = new TwoTieredDistribution(
                    0,
                    twoTieredTier, 
                    twoTieredSplit, 
                    sessions,
                    debugMode);
            break;
        case Dist::Skewed:
            distributionGenerator = new SkewedDistribution(
                    lowerBound, 
                    sessions,
                    debugMode);
            break;
        case Dist::Binomial:
            distributionGenerator = new BinomialDistribution(
                    lowerBound,
                    sessions,
                    debugMode);
            break;
        default:
            distributionGenerator = new UniformDistribution(
                    lowerBound,
                    sessions,
                    debugMode);
            break;
    }
}

void ConferenceConflictDetector::selectConflictSize() {
    switch(conflictSize) {
        case ConflictSizeConstrinat::M:
            conflictHandler = new ConflictList(sessions);
            break;
        case ConflictSizeConstrinat::N2:
            conflictHandler = new ConflictGraph(sessions);
            break;
        default:
            conflictHandler = new ConflictGraph(sessions);
    }
}

void ConferenceConflictDetector::addConflictSet(std::set<int> set) {
        if (debugMode == 1 ) {
            std::cout << "ConferenceConflictDetector::addConflictSet: Starting" << std::endl;
        }
            if (debugMode >= 2 ) {
                std::cout << "ConferenceConflictDetector::addConflictSet: Starting pair creation" << std::endl;
                start = std::chrono::system_clock::now();
            }
        
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
        
            if (debugMode >= 2 ) {
                std::cout << "Total unique pairs after new set added - " << conflictHandler->getUniqueConflictCount() << std::endl;
                std::cout << "ConferenceConflictDetector::addConflictSet: Finished pair creation in ";
                auto end = std::chrono::system_clock::now() - start;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration  << "ms" << std::endl;
            }
        if (debugMode == 1 ) {
            std::cout << "ConferenceConflictDetector::addConflictSet: Ending" << std::endl;
        }
}

void ConferenceConflictDetector::initalDebug() {
    if(debugMode <= 0) {
        return;
    }
    
    std::cout << "Creating Conference Conflict Detector with parameters" << std::endl;
    std::cout << "Sessions              -- " << sessions << std::endl;
    std::cout << "Attendees             -- " << attendees << std::endl;
    std::cout << "Sessions per Attendee -- " << sesPerAtte << std::endl;
    std::cout << "Lower Bound           -- " << lowerBound << std::endl;
    std::cout << "Two Tiered Tier       -- " << twoTieredTier << std::endl;
    std::cout << "Two Tiered Split      -- " << twoTieredSplit << std::endl;
    std::cout << "Show Output every     -- " << showOutput << std::endl;
    std::cout << "Show Output new line  -- " << showOutputNewLine << std::endl;
    std::cout << "P array batch size    -- " << pBatchSize << std::endl;
    std::cout << "E array batch size    -- " << eBatchSize << std::endl;
    std::cout << "Using distribution    -- ";
    switch(distribution) {
        case Dist::Uniform:
            std::cout << "UNIFORM";
            break;
        case Dist::Skewed:
            std::cout << "SKEWED";
            break;
        case Dist::Tiered:
            std::cout << "TIERED";
            break;
        case Dist::Binomial:
            std::cout << "BINOMIAL";
            break;
        default:
            std::cout << "UNIFORM";
            break;
    }
    std::cout << std::endl;
        
    std::cout << "Using constraint size -- ";
    switch(conflictSize) {
        case ConflictSizeConstrinat::M:
            std::cout << "M";
            break;
        case ConflictSizeConstrinat::N2:
            std::cout << "N2";
            break;
        default:
            std::cout << "N2";
            break;
    }
    std::cout << std::endl;
    
    std::cout << "Using debug mode      -- " << debugMode << std::endl;
}
