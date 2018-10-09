/* 
 * File:   RandomNumberGenerator.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 1:15 PM
 */

#include "RandomNumberGenerator.h"

int RandomNumberGenerator::UniformRandomGenerator(
        const int lowerBound, 
        const int upperBound) {
    if(lowerBound < 0) {
        throw std::invalid_argument(
                "UniformRandomGenerator: Lower bound must >= to 0");
    }
    if(upperBound <= lowerBound) {
        throw std::invalid_argument(
                "UniformRandomGenerator: Upper bound must be > lower bound");
    }
    
    return randomNumber(lowerBound, upperBound);
}

int RandomNumberGenerator::SkewedRandomGenerator(
        const int lowerBound, 
        const int upperBound) {
    if(lowerBound < 0) {
        throw std::invalid_argument(
                "SkewedRandomGenerator: Lower bound must be >= to 0");
    }
    if(upperBound <= lowerBound) {
        throw std::invalid_argument(
                "SkewedRandomGenerator: Upper bound must be > the lower bound");
    }
    
    // Inclusive range
    int range = (upperBound)-lowerBound;
    
    // Chosen random number
    int pickedRandom;
    // Percent that value is chosen
    float percentPicked;
    // Random chance to see if value is chosen
    float pickPercentage;
    
    do {
        pickedRandom = randomNumber(lowerBound, upperBound);
        percentPicked = 1 - (pickedRandom - lowerBound) / (float)range;
        pickPercentage = 1 - (randomNumber(0, range) / (float)range);
    } while(percentPicked < pickPercentage);

    return pickedRandom;
}

int RandomNumberGenerator::TwoTieredRandomGenerator(
        const int lowerBound,
        const int tier, 
        const float split, 
        const int upperBound) {
    if(lowerBound < 0) {
        throw std::invalid_argument(
                "TwoTieredRandomGenerator: Lower bound must be >= to 0");
    }
    if(upperBound <= lowerBound) {
        throw std::invalid_argument(
                "TwoTieredRandomGenerator: Upper bound must be >  lower bound");
    }
    if(tier <= lowerBound || tier >= upperBound) {
        throw std::invalid_argument(
                "TwoTieredRandomGenerator: lower bound < tier < upper bound");
    }
    if(split < 0 || split > 1) {
        throw std::invalid_argument(
                "TwoTieredRandomGenerator: Split must be a percentage [0,1]");
    }
    
    // Gets a number between [0,1)
    float percent = randomNumber(0, 1000) / (float)1000;
    
    // Tier is always greater than lower, however randomNumber() adds lowerBound
    //  to the number and in the case that percent >= split, the new lowerBound
    //  is tier.
    int newUpper = upperBound - (tier - lowerBound);
    
    // Higher split results in more on the left side
    if(percent < split) {
        // Random number between [lowerBound, tier)
        return randomNumber(lowerBound, tier);
    } else {
        // Random number between [tier, upperBound)
        return randomNumber(tier, newUpper);
    }
}

int RandomNumberGenerator::BinomialRandomGenerator(
        const int lowerBound, 
        const int upperBound) {
    if(lowerBound < 0) {
        throw std::invalid_argument(
                "BinomialRandomGenerator: Lower bound must be >= to 0");
    }
    if(upperBound <= lowerBound) {
        throw std::invalid_argument(
                "BinomialRandomGenerator: Upper bound must be > lower bound");
    }
    
    int newLower = lowerBound/2;
    // Automatically truncates but because randomNumber is exclusive for
    //  upperBound, add an additional one to make sure BinomialRandomGenerator
    //  still follows upperBound exclusivity
    int newUpper = (upperBound/2) + 1;
    
    int binomialNumber;
    do {
    // Two uniform random number generators result in a binomial distribution
    //  binomialNumber = [newLower + newUpper) + [newLower + newUpper)
        binomialNumber = randomNumber(newLower, newUpper) 
                             + randomNumber(newLower, newUpper);
    } while(binomialNumber < lowerBound || binomialNumber >= upperBound);
    
    return binomialNumber;
}

void RandomNumberGenerator::seedGenerator(const time_t seed) {
    srand(seed);
}

int RandomNumberGenerator::randomNumber(
        const int lowerBound, 
        const int upperBound) {
    return (rand() % (upperBound-lowerBound)) + lowerBound;
}