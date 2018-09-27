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
            const Dist dist);
    
    ConferenceConflictDetector(const ConferenceConflictDetector& orig);
    virtual ~ConferenceConflictDetector();
    
    void selectConflictSize(ConflictSizeConstrinat size);
    void generateConflicts(int showOutput);
    void handleResults(std::string output);
private:
    int sessions;
    int attendees;
    int sesPerAtte;
    
    Dist distribution;
    Distribution* distributionGenerator;
    
    ConflictHandler* conflictHandler;
    
    void addConflictSet(std::set<int> set);
};

#endif /* CONFERENCECONFLICTDETECTOR_H */

