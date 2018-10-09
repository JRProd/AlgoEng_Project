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
        const int upperB,
        const int debug) {
    if(lowerB < 0) {
        throw std::invalid_argument("TwoTieredDistribution: Lower bound must be greater than or equal to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument("TwoTieredDistribution: Upper bound must be strictly greater than the lower bound");
    }
    if(tr <= lowerB || tr >= upperB) {
        throw std::invalid_argument("TwoTieredDistribution: Tier must be strictly between the lower bound and upper bound");
    }
    if(splt < 0 || splt > 1) {
        throw std::invalid_argument("TwoTieredDistribution: Split must be a percentage [0,1]");
    }
    
    lowerBound = lowerB;
    tier = tr;
    split = splt;
    upperBound = upperB;
    
    useTieredRng = true;
    
    debugMode = debug;
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
        if(debugMode == 1) {
            std::cout << "Distribution::generateSessions: Starting" << std::endl;
        }
    
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument("Distribution::generateSessions: Attempting to generate to many unique values");
    }
    
    std::set<int> sessions;
    int startingLowerBound = lowerBound;
    int startingUpperBound = upperBound;
    
            if(debugMode >= 2) {
                std::cout << "Distribution::generateSessions: Starting set creation" << std::endl;
                start = std::chrono::system_clock::now();
            }
                if(debugMode >= 3) {
                    std::cout << "Lower -- Upper" << std::endl;
                }
    
    // If all the upper tier have been choose, no more reason to use Tiered RNG
    //  Reset each time generating new sessions.
    useTieredRng = true;
    while(sessions.size() != size) {
        int session = generateSession();
        if(session == lowerBound) {
            lowerBound = lowerBound+1;
                        if(debugMode >= 3) {
                            std::cout << lowerBound << " -- " << upperBound << std::endl;
                        }
            
            // If the lowerBound is now at the tier, switch to uniform RNG
            if(tier == lowerBound) {
                useTieredRng = false;
            }
        }
        if(session == upperBound-1) {
            upperBound = upperBound-1;
                        if(debugMode >= 3) {
                            std::cout << lowerBound << " -- " << upperBound << std::endl;
                        }
        }
        sessions.insert(session);
    }
    
            if (debugMode >= 2 ) {
                std::cout << "Distribution::generateSessions: Finished set creation in ";
                auto end = std::chrono::system_clock::now() - start;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration  << "ms" << std::endl;
            }
    
    lowerBound = startingLowerBound;
    upperBound = startingUpperBound;
    
        if (debugMode == 1) {
            std::cout << "Distribution::generateSessions: Finished" << std::endl;;
        }
    return sessions;
}


