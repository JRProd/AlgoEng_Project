/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RandomGeneratorUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Sep 11, 2018, 9:51:01 AM
 */

#include <iostream>
#include <stdlib.h>

#include "RandomGeneratorUnitTest.h"
#include "../../utils/RandomNumberGenerator.h"

const int LOWER_BOUND = 0;
const int TIER = 3;
const float SPLIT = 0.8;
const int UPPER_BOUND = 100;
const int RANGE = UPPER_BOUND - LOWER_BOUND;

const int UNIFORM_SIZE = 1000000;
const float UNIFORM_DIFF = .125;

const int SKEWED_SIZE = 1000000;
const float SKEWED_DIFF = ((1.0/RANGE)*10)+.2;

const int TWO_TIERED_SIZE = 100000;
const float TWO_TIERED_DIFF = .25;

const int BINOMIAL_SIZE = 1000000;
const float BINOMIAL_DIFF = .4;

const int MAX_ALLOWABLE_DIFFERENCES = 5;

CPPUNIT_TEST_SUITE_REGISTRATION(RandomGeneratorUnitTest);

RandomGeneratorUnitTest::RandomGeneratorUnitTest() {
}

RandomGeneratorUnitTest::~RandomGeneratorUnitTest() {
}

void RandomGeneratorUnitTest::setUp() {
}

void RandomGeneratorUnitTest::tearDown() {
}

void RandomGeneratorUnitTest::testUniformRandomGenerator() {
    std::cout << "###### Starting Uniform Random Generator Test ######" << std::endl;
    int* uniformDistro = new int[UNIFORM_SIZE];
    
    for(int i = 0; i < UNIFORM_SIZE; i++) {
        *(uniformDistro+i) = RandomNumberGenerator::UniformRandomGenerator(
                LOWER_BOUND,
                UPPER_BOUND);
    }
    
    const int* histo = histogram(uniformDistro, UNIFORM_SIZE, RANGE);
    
    if(*(histo+RANGE) != UNIFORM_SIZE) {
        std::cout << "----ERROR: Uniform Histogram has missing values" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    if(uniformRngHelper(histo, RANGE)) {
        CPPUNIT_ASSERT(true);
    } else {
        std::cout << "----ERROR: Uniform Distribution is too different" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    std::cout << std::endl;
}

bool RandomGeneratorUnitTest::uniformRngHelper(const int* const histo, const int buckets) {
    int isUniform = 0;
    
    std::cout << "Max difference = " << UNIFORM_DIFF << std::endl;
    for(int i = 0; i < buckets-1; i++) {
        float average = (float)(*(histo+i) + *(histo+i+1))/2.0;
        float percentChange = std::abs((*(histo+i) - *(histo+i+1)))/average;
        if(percentChange > UNIFORM_DIFF) {
            std::cout << "Val1:" << *(histo+i) << " Val2:" << *(histo+i+1) << " Percent Change:" << percentChange << std::endl;
            isUniform++;
        }
        
        if(isUniform >= MAX_ALLOWABLE_DIFFERENCES) {
            return false;
        }
    }
    
    return true;
}

void RandomGeneratorUnitTest::testSkewedRandomGenerator() {
    std::cout << "###### Starting Skewed Random Generator Test ######" << std::endl;
    int* skewedDistro = new int[SKEWED_SIZE];
    
    for(int i = 0; i < SKEWED_SIZE; i++) {
        *(skewedDistro+i) = RandomNumberGenerator::SkewedRandomGenerator(
                LOWER_BOUND,
                UPPER_BOUND);
    }
    
    const int* histo = histogram(skewedDistro, SKEWED_SIZE, RANGE);
    
    if(*(histo+RANGE) != SKEWED_SIZE) {
        std::cout << "----ERROR: Skewed Histogram has missing values" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    if(skewedRngHelper(histo, RANGE)) {
        CPPUNIT_ASSERT(true);
    } else {
        std::cout << "----ERROR: Skewed Distribution is too different" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    std::cout << std::endl;
}

bool RandomGeneratorUnitTest::skewedRngHelper(const int* const histo, const int buckets) {
    int isSkewed = 0;
    
    std::cout << "Max difference = " << SKEWED_DIFF << std::endl;
    for(int i = 0; i < buckets-1; i++) {
        float average = (float)(*(histo+i) + *(histo+i+1))/2.0;
        float percentChange = std::abs((*(histo+i) - *(histo+i+1)))/average;
        if(percentChange > SKEWED_DIFF) {
            std::cout << "Val1:" << *(histo+i) << " Val2:" << *(histo+i+1) << " Percent Change:" << percentChange << std::endl;
            isSkewed++;
        }
        
        if(isSkewed >= MAX_ALLOWABLE_DIFFERENCES) {
            return false;
        }
    }
    
    return true;
}

void RandomGeneratorUnitTest::testTwoTieredRandomGenerator() {
    std::cout << "###### Starting Two Tiered Random Generator Test ######" << std::endl;
    int* twoTieredDistro = new int[TWO_TIERED_SIZE];
    
    for(int i = 0; i < TWO_TIERED_SIZE; i++) {
        *(twoTieredDistro+i) = RandomNumberGenerator::TwoTieredRandomGenerator(
                LOWER_BOUND,
                TIER,
                SPLIT,
                UPPER_BOUND);
    }
    
    const int* histo = histogram(twoTieredDistro, TWO_TIERED_SIZE, RANGE);
    
    if(*(histo+RANGE) != TWO_TIERED_SIZE) {
        std::cout << "----ERROR: Two Tiered Histogram has missing values" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    if(twoTieredRngHelper(histo, RANGE)) {
        CPPUNIT_ASSERT(true);
    } else {
        std::cout << "----ERROR: Two Tiered Distribution is too different" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    std::cout << std::endl;
}

bool RandomGeneratorUnitTest::twoTieredRngHelper(const int* const histo, const int buckets) {
    int isTwoTiered = -1; // -1 Because when switching tiers, the difference will be vast
    
    std::cout << "Max difference = " << TWO_TIERED_DIFF << std::endl;
    for(int i = 0; i < buckets-1; i++) {
        float average = (float)(*(histo+i) + *(histo+i+1))/2.0;
        float percentChange = std::abs((*(histo+i) - *(histo+i+1)))/average;
        if(percentChange > TWO_TIERED_DIFF) {
            std::cout << "Val1:" << *(histo+i) << " Val2:" << *(histo+i+1) << " Percent Change:" << percentChange << std::endl;
            isTwoTiered++;
        }
        
        if(isTwoTiered >= MAX_ALLOWABLE_DIFFERENCES) {
            return false;
        }
    }
    
    return true;
}

void RandomGeneratorUnitTest::testBinomialRandomGenerator() {
    std::cout << "###### Starting Binomial Random Generator Test ######" << std::endl;
    int* binomialDistro = new int[BINOMIAL_SIZE];
    
    for(int i = 0; i < BINOMIAL_SIZE; i++) {
        *(binomialDistro+i) = RandomNumberGenerator::BinomialRandomGenerator(
                LOWER_BOUND,
                UPPER_BOUND);
    }
    
    const int* histo = histogram(binomialDistro, BINOMIAL_SIZE, RANGE);
    
    if(*(histo+RANGE) != BINOMIAL_SIZE) {
        std::cout << "----ERROR: Binomial Histogram has missing values" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    if(binomialRngHelper(histo, RANGE)) {
        CPPUNIT_ASSERT(true);
    } else {
        std::cout << "----ERROR: Binomial Distribution is too different" << std::endl;
        CPPUNIT_ASSERT(false);
    }
    
    std::cout << std::endl;
}

bool RandomGeneratorUnitTest::binomialRngHelper(const int* const histo, const int buckets) {
    int isBinomial = 0;
    
    std::cout << "Max difference = " << BINOMIAL_DIFF << std::endl;
    for(int i = 0; i < buckets-1; i++) {
        float average = (float)(*(histo+i) + *(histo+i+1))/2.0;
        float percentChange = std::abs((*(histo+i) - *(histo+i+1)))/average;
        if(percentChange > BINOMIAL_DIFF) {
            std::cout << "Val1:" << *(histo+i) << " Val2:" << *(histo+i+1) << " Percent Change:" << percentChange << std::endl;
            isBinomial++;
        }
        
        if(isBinomial >= MAX_ALLOWABLE_DIFFERENCES) {
            return false;
        }
    }
    
    return true;
}

/**
 * 
 * @param histo - Histogram to count
 * @param buckets - Number of buckets in the histogram
 * @return int - Total value contained in the buckets
 */
const int RandomGeneratorUnitTest::countHisto(const int* const histo, const int buckets) {
    int total = 0;
    for(int i = 0; i < buckets; i++) {
        total += *(histo+i);
    }

    return total;
}

/** Histogram a list of numbers
 *
 * @param list - List of integers [1,10]
 * @param size - Size of the above list
 *
 * @output int* - Histogram with the value at a index = to the times that index
 *  was in the list. Will always be of size UPPER_BOUND+1 (last value is total)
 */
const int* RandomGeneratorUnitTest::histogram(const int* const list, const int size, const int buckets) {
    int* histo = new int[buckets+1];
    std::fill_n(histo, buckets, 0);
    for(int i = 0; i < size; i++) {
        // Offset histo pointer by the current value in the list -1
        int value = *(list+i);
        *(histo+value) = *(histo+value) + 1;
    }

    *(histo+buckets) = countHisto(histo, buckets);

    return histo;
}

