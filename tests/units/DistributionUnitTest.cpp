/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DistributionUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Sep 11, 2018, 12:18:21 AM
 */

#include <iostream>

#include "DistributionUnitTest.h"
#include "../../distributions/Distribution.h"
#include "../../distributions/UniformDistribution.h"
#include "../../distributions/SkewedDistribution.h"
#include "../../distributions/TwoTieredDistribution.h"
#include "../../distributions/BinomialDistribution.h"

const int LOWER_BOUND = 0;
const int TIER = 1000;
const float SPLIT = 0.8;
const int UPPER_BOUND = 100000;

const int UNIFORM_DISTRO_SIZE = 1000;
const int SKEWED_DISTRO_SIZE = 1000;
const int TWO_TIERED_DISTRO_SIZE = 1000;
const int BINOMIAL_DISTRO_SIZE = 1000;

CPPUNIT_TEST_SUITE_REGISTRATION(DistributionUnitTest);

DistributionUnitTest::DistributionUnitTest() {
}

void DistributionUnitTest::setUp() {
}

void DistributionUnitTest::tearDown() {
}

void DistributionUnitTest::testUniformDistribution() {
    std::cout << "###### Starting Uniform Distribution Test ######" << std::endl;
    Distribution* uniformDistro = new UniformDistribution(LOWER_BOUND, UPPER_BOUND, 0);
    std::set<int> uniformSet = uniformDistro->generateSessions(
            UNIFORM_DISTRO_SIZE);
    
    std::cout << "Size of the set is " << uniformSet.size() << std::endl;
    
    if(uniformSet.size() != UNIFORM_DISTRO_SIZE) {
        CPPUNIT_ASSERT(false);
    }
    CPPUNIT_ASSERT(true);
    
    std::cout << "Test Finished" << std::endl << std::endl;
}

void DistributionUnitTest::testSkewedDistribution() {
    std::cout << "###### Starting Skewed Distribution Test ######" << std::endl;
    Distribution* skewedDistro = new SkewedDistribution(LOWER_BOUND, UPPER_BOUND, 0);
    std::set<int> skewedSet = skewedDistro->generateSessions(
            SKEWED_DISTRO_SIZE);
    
    std::cout << "Size of the set is " << skewedSet.size() << std::endl;
    
    if(skewedSet.size() != SKEWED_DISTRO_SIZE) {
        CPPUNIT_ASSERT(false);
    }
    CPPUNIT_ASSERT(true);
    
    std::cout << "Test Finished" << std::endl << std::endl;
}

void DistributionUnitTest::testTwoTieredDistribution() {
    std::cout << "###### Starting Two Tiered Distribution Test ######" << std::endl;
    Distribution* twoTieredDistro = new TwoTieredDistribution(LOWER_BOUND, TIER, SPLIT, UPPER_BOUND, 0);
    std::set<int> twoTieredSet = twoTieredDistro->generateSessions(
            TWO_TIERED_DISTRO_SIZE);
    
    std::cout << "Size of the set is " << twoTieredSet.size() << std::endl;
    
    if(twoTieredSet.size() != TWO_TIERED_DISTRO_SIZE) {
        CPPUNIT_ASSERT(false);
    }
    CPPUNIT_ASSERT(true);
    
    std::cout << "Test Finished" << std::endl << std::endl;
}

void DistributionUnitTest::testBinomialDistribution() {
    std::cout << "###### Starting Binomial Distribution Test ######" << std::endl;
    Distribution* binomialDistro = new BinomialDistribution(LOWER_BOUND, UPPER_BOUND, 0);
    std::set<int> binomialSet = binomialDistro->generateSessions(
            BINOMIAL_DISTRO_SIZE);
    
    std::cout << "Size of the set is " << binomialSet.size() << std::endl;
    
    if(binomialSet.size() != BINOMIAL_DISTRO_SIZE) {
        CPPUNIT_ASSERT(false);
    }
    CPPUNIT_ASSERT(true);
    
    std::cout << "Test Finished" << std::endl << std::endl;
}

void DistributionUnitTest::printSet(std::set<int> set) {
    std::cout << "[";
    for(const int number: set) {
        std::cout << number << ", ";
    }
    std::cout << "]" << std::endl;
}