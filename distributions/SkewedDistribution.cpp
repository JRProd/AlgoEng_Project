/* 
 * File:   SkewedDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 7:41 PM
 */

#include "SkewedDistribution.h"

SkewedDistribution::SkewedDistribution(
        const int lowerB, 
        const int upperB,
        const int debug) {
    if(lowerB < 0) {
        throw std::invalid_argument(
                "SkewedDistribution: Lower bound must >= to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument(
                "SkewedDistribution: Upper bound must be > lower bound");
    }
    
    lowerBound = lowerB;
    upperBound = upperB;
    debugMode = debug;
}

SkewedDistribution::~SkewedDistribution() {

}


Dist SkewedDistribution::whichDistribution() {
    return Dist::Skewed;
}


const int SkewedDistribution::generateSession() {
    return RandomNumberGenerator::SkewedRandomGenerator(lowerBound, upperBound);
}