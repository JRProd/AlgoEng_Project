/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferenceConflictDetector.h
 * Author: jake.rowland
 *
 * Created on September 25, 2018, 9:47 AM
 */

#ifndef CONFERENCECONFLICTDETECTOR_H
#define CONFERENCECONFLICTDETECTOR_H

#include <iostream>
#include <chrono>

#include "ConferenceConflictParams.h"

#include "../conflicts/ConflictHandler.h"
#include "../conflicts//ConflictGraph.h"
#include "../conflicts/ConflictList.h"

#include "../distributions/Distribution.h"
#include "../distributions/BinomialDistribution.h"
#include "../distributions/TwoTieredDistribution.h"
#include "../distributions/SkewedDistribution.h"
#include "../distributions/UniformDistribution.h"

#include "../utils/FileHandler.h"
#include "../utils/MathUtils.h"

class ConferenceConflictDetector {
public:
    ConferenceConflictDetector(const int N, 
            const int S, 
            const int K, 
            const Dist dist,
            const ConflictSizeConstrinat size);
    
    ConferenceConflictDetector(
            const ConferenceConflictParams* params);
    
    virtual ~ConferenceConflictDetector();
    
    void generateConflicts();
    void handleResults(std::string output);
private:
    int sessions;
    int attendees;
    int sesPerAtte;
    
    int lowerBound = 0;
    
    int twoTieredTier = 100;
    float twoTieredSplit = .8;
    
    int showOutput = 0;
    int showOutputNewLine = 20;
    
    int pBatchSize = 1000;
    int eBatchSize = 1000;
    
    int debugMode = false;
    std::chrono::time_point<std::chrono::system_clock> start;
    
    Dist distribution;
    Distribution* distributionGenerator;
    
    ConflictSizeConstrinat conflictSize;
    ConflictHandler* conflictHandler;
    
    void setUpDistribution();
    void selectConflictSize();
    
    void addConflictSet(std::set<int> set);
    
    void initalDebug();
};

#endif /* CONFERENCECONFLICTDETECTOR_H */

