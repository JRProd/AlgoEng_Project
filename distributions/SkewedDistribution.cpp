/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SkewedDistribution.cpp
 * Author: jake.rowland
 * 
 * Created on September 10, 2018, 7:41 PM
 */

#include "SkewedDistribution.h"

#include <iostream>
SkewedDistribution::SkewedDistribution(
        const int lowerB, 
        const int upperB,
        const int debug) {
    if(lowerB < 0) {
        throw std::invalid_argument("SkewedDistribution: Lower bound must be greater than or equal to 0");
    }
    if(upperB <= lowerB) {
        throw std::invalid_argument("SkewedDistribution: Upper bound must be strictly greater than the lower bound");
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

