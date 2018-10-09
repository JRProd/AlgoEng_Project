/* 
 * File:   Distrobution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 12:16 PM
 */

#include "Distribution.h"

Distribution::Distribution() {
    RandomNumberGenerator::seedGenerator(time(nullptr));
}


Distribution::~Distribution() {
}


std::set<int> Distribution::generateSessions(const int size) {
        if(debugMode == 1) {
            std::cout << "Distribution::generateSessions:" <<
                        " Starting" << std::endl;
        }
    
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument("Distribution::generateSessions:" <<
                        " Attempting to generate to many unique values");
    }
    
    std::set<int> sessions;
    int startingLowerBound = lowerBound;
    int startingUpperBound = upperBound;
    
            if(debugMode >= 2) {
                std::cout << "Distribution::generateSessions:" <<
                        " Starting set creation" << std::endl;
                start = std::chrono::system_clock::now();
            }
                if(debugMode >= 3) {
                    std::cout << "Lower -- Upper" << std::endl;
                }
    
    while(sessions.size() != size) {
        int session = generateSession();
        if(session == lowerBound) {
            lowerBound = lowerBound+1;
                        if(debugMode >= 3) {
                            std::cout << lowerBound << " -- " << upperBound 
                                    << std::endl;
                        }
        }
        if(session == upperBound-1) {
            upperBound = upperBound-1;
                        if(debugMode >= 3) {
                            std::cout << lowerBound << " -- " << upperBound 
                                    << std::endl;
                        }
        }
        sessions.insert(session);
    }
    
                if (debugMode >= 2 ) {
                    std::cout << "Distribution::generateSessions:" <<
                        " Finished set creation in ";
                    auto end = std::chrono::system_clock::now() - start;
                    long duration = 
                        std::chrono::duration_cast<
                            std::chrono::milliseconds>(end).count();
                    std::cout << duration  << "ms" << std::endl;
                }
    
    lowerBound = startingLowerBound;
    upperBound = startingUpperBound;
    
        if (debugMode == 1) {
            std::cout << "Distribution::generateSessions:" <<
                        " Finished" << std::endl;;
        }
    return sessions;
}