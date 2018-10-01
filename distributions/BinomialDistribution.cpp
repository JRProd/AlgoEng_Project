/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinomialDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 8:38 PM
 */

#include "BinomialDistribution.h"

BinomialDistribution::BinomialDistribution(
        const int lowerB, 
        const int upperB,
        const int debug) {
    if(lowerB < 0) {
        throw std::invalid_argument("BinomialDistribution: Lower bound must be greater than or equal to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument("BinomialDistribution: Upper bound must be strictly greater than the lower bound");
    }
    
    lowerBound = lowerB;
    upperBound = upperB;
    debugMode = debug;
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

