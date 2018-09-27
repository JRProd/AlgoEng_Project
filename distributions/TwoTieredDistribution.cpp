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
        const int upperB) {
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
}

TwoTieredDistribution::~TwoTieredDistribution() {

}


Dist TwoTieredDistribution::whichDistribution() {
    return Dist::Tiered;
}


const int TwoTieredDistribution::generateSession() {
    return RandomNumberGenerator::TwoTieredRandomGenerator(
            lowerBound,
            tier,
            split,
            upperBound);
}


