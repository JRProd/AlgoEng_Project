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

Distribution::~Distribution() {

}

std::set<int> Distribution::generateSessions(const int size) {
    if(size > upperBound - lowerBound) {
        throw std::invalid_argument("Distribution::generateSessions: Attempting to generate to many unique values");
    }
    std::set<int> sessions;
    
    while(sessions.size() != size) {
        sessions.insert(generateSession());
    }
    
    return sessions;
}

