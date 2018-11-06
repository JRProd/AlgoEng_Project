/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TwoTiedDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 8:26 PM
 */

#include "TwoTieredDistribution.h"

TwoTieredDistribution::TwoTieredDistribution(
        const int lowerB,
        const int tr,
        const float splt,
        const int upperB) {
    if(lowerB < 0) {
        throw std::invalid_argument(
                "TwoTieredDistribution: Lower bound must >= to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument(
                "TwoTieredDistribution: Upper bound must be > lower bound");
    }
    if(tr <= lowerB || tr >= upperB) {
        throw std::invalid_argument(
                "TwoTieredDistribution: lower bound < tier < upperBound");
    }
    if(splt < 0 || splt > 1) {
        throw std::invalid_argument(
                "TwoTieredDistribution: Split must be a percentage [0,1]");
    }
    
    lowerBound = lowerB;
    tier = tr;
    split = splt;
    upperBound = upperB;
    
    useTieredRng = true;
}

TwoTieredDistribution::~TwoTieredDistribution() {
}


Dist TwoTieredDistribution::whichDistribution() {
    return Dist::Tiered;
}


const int TwoTieredDistribution::generateSession() {
    if (useTieredRng) {
        return RandomNumberGenerator::TwoTieredRandomGenerator(
                lowerBound,
                tier,
                split,
                upperBound);
    } else {
        return RandomNumberGenerator::UniformRandomGenerator(
                lowerBound,
                upperBound);
    }
}

std::set<int> TwoTieredDistribution::generateSessions(const int size) {
    
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument(
                "TwoTieredDistribution::generateSessions: Generating to many values");
    }
    
    std::set<int> sessions;
    int startingLowerBound = lowerBound;
    int startingUpperBound = upperBound;
    
    // If all the upper tier have been choose, no more reason to use Tiered RNG
    //  Reset each time generating new sessions.
    useTieredRng = true;
    while(sessions.size() != size) {
        int session = generateSession();
        if(session == lowerBound) {
            lowerBound = lowerBound+1;
            
            // If the lowerBound is now at the tier, switch to uniform RNG
            if(tier == lowerBound) {
                useTieredRng = false;
            }
        }
        if(session == upperBound-1) {
            upperBound = upperBound-1;
        }
        sessions.insert(session);
    }
    
    lowerBound = startingLowerBound;
    upperBound = startingUpperBound;

    return sessions;
}


