/* 
 * File:   UniformDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 5:20 PM
 */

#include "UniformDistribution.h"


UniformDistribution::UniformDistribution(
        const int lowerB, 
        const int upperB,
        const int debug) {
    if(lowerB < 0) {
        throw std::invalid_argument("UniformDistribution: Lower bound must be greater than or equal to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument("UniformDistribution: Upper bound must be strictly greater than the lower bound");
    }
    
    lowerBound = lowerB; 
    upperBound = upperB;
    debugMode = debug;
}

UniformDistribution::~UniformDistribution() {

}


Dist UniformDistribution::whichDistribution() {
    return Dist::Uniform;
}


const int UniformDistribution::generateSession() {
    return RandomNumberGenerator::UniformRandomGenerator(
            lowerBound, 
            upperBound);
}



