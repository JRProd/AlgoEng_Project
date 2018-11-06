/* 
 * File:   BinomialDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 8:38 PM
 */

#include "BinomialDistribution.h"

BinomialDistribution::BinomialDistribution(
        const int lowerB, 
        const int upperB) {
    if(lowerB < 0) {
        throw std::invalid_argument(
                "BinomialDistribution: Lower bound must be >= to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument(
                "BinomialDistribution: Upper bound must be > lower bound");
    }
    
    lowerBound = lowerB;
    upperBound = upperB;
}

BinomialDistribution::~BinomialDistribution() {

}


Dist BinomialDistribution::whichDistribution() {
    return Dist::Binomial;
}


const int BinomialDistribution::generateSession() {
    return RandomNumberGenerator::BinomialRandomGenerator(
            lowerBound, 
            upperBound);
}