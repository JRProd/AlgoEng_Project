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

#include "TwoTiedDistribution.h"
#include "../utils/RandomNumberGenerator.h"

TwoTiedDistribution::TwoTiedDistribution(
        const int lowerB,
        const int tr,
        const float splt,
        const int upperB) {
    lowerBound = lowerB;
    tier = tr;
    split = splt;
    upperBound = upperB;
}

const int TwoTiedDistribution::generateSession() {
    return RandomNumberGenerator::TwoTieredRandomGenerator(
            lowerBound,
            tier,
            split,
            upperBound);
}


