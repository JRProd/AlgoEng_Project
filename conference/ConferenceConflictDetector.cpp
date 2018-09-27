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
        const Dist dist) {
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
    
    switch(distribution) {
        case Dist::Uniform:
            distributionGenerator = new UniformDistribution(0,N);
            break;
        case Dist::Tiered:
            distributionGenerator = new TwoTieredDistribution(0,100, .8, N);
            break;
        case Dist::Skewed:
            distributionGenerator = new SkewedDistribution(0,N);
            break;
        case Dist::Binomial:
            distributionGenerator = new BinomialDistribution(0,N);
            break;
        default:
            distributionGenerator = new UniformDistribution(0,N);
            break;
    }
}

ConferenceConflictDetector::ConferenceConflictDetector(const ConferenceConflictDetector& orig) {
}

ConferenceConflictDetector::~ConferenceConflictDetector() {
    delete distributionGenerator;
    delete conflictHandler;
}

void ConferenceConflictDetector::selectConflictSize(ConflictSizeConstrinat size) {
    switch(size) {
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

void ConferenceConflictDetector::generateConflicts(int showOutput) {
    bool shouldShow = false;
    if(showOutput > 0 ) {
        std::cout << "ConferenceConflictDetector::generateConflicts: Showing every " << showOutput << "th iteration" << std::endl;
        shouldShow = true;
    }
    for(int attendee = 0; attendee < attendees; attendee++) {
        std::set<int> set = distributionGenerator->generateSessions(sesPerAtte);
        addConflictSet(set);
        conflictHandler->addConflictCount(MathUtils::pairs(set.size()));
        
        if(shouldShow) {
            if(attendee % showOutput == 0 && attendee != 0) {
                std::cout << "." ;
            }
            if(attendee % (showOutput*20) == 0 && attendee != 0) {
                std::cout << std::endl;
            }
        }
    }
    
    std::cout << std::endl;
}

void ConferenceConflictDetector::handleResults(std::string output) {
    FileHandler fileHandler;
    fileHandler.openFile(output);
    
    //N Output
    fileHandler.write("N", sessions);
    //M Output
    fileHandler.write("M", conflictHandler->getUniqueConflictCount());
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
    
    std::cout << "Begin writing P/E array" << std::endl;
    int** peArray = conflictHandler->peArray();
    //P[] Output
    fileHandler.writeList("P", *(peArray+0), sessions, 1000);
    //E[] Output
    fileHandler.writeList("E", *(peArray+1), conflictHandler->getSizeOfEArray(), 1000);
    
    delete[] *(peArray+0);
    delete[] *(peArray+1);
    delete[] peArray;
    
    fileHandler.closeFile();
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





