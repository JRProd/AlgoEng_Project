/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

#include <iostream>
std::set<int> Distribution::generateSessions(const int size) {
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument("Distribution::generateSessions: Attempting to generate to many unique values");
    }
    std::set<int> sessions;
    int startingLowerBound = lowerBound;
    int startingUpperBound = upperBound;
    while(sessions.size() != size) {
        int session = generateSession();
        std::cout << session << std::endl;
        if(session == lowerBound) {
            lowerBound = lowerBound+1;
            std::cout << lowerBound << " - " << upperBound << std::endl;
        }
        if(session == upperBound-1) {
            upperBound = upperBound-1;
            std::cout << lowerBound << " - " << upperBound << std::endl;
        }
        sessions.insert(session);
    }
    
    lowerBound = startingLowerBound;
    upperBound = startingUpperBound;
    
    return sessions;
}

