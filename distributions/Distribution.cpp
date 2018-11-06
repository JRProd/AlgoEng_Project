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
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument(
                "Distribution::generateSessions: Generating to many values");
    }
    
    std::set<int> sessions;
    int startingLowerBound = lowerBound;
    int startingUpperBound = upperBound;
    while(sessions.size() != size) {
        int session = generateSession();
        if(session == lowerBound) {
            lowerBound = lowerBound+1;
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