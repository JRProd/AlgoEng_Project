/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RandomGeneratorUnitTest.h
 * Author: jake.rowland
 *
 * Created on Sep 11, 2018, 9:51:01 AM
 */

#ifndef RANDOMGENERATORUNITTEST_H
#define RANDOMGENERATORUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

class RandomGeneratorUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RandomGeneratorUnitTest);

    CPPUNIT_TEST(testUniformRandomGenerator);
    CPPUNIT_TEST(testSkewedRandomGenerator);
    CPPUNIT_TEST(testTwoTieredRandomGenerator);
    CPPUNIT_TEST(testBinomialRandomGenerator);

    CPPUNIT_TEST_SUITE_END();

public:
    RandomGeneratorUnitTest();
    virtual ~RandomGeneratorUnitTest();
    void setUp();
    void tearDown();

private:
    void testUniformRandomGenerator();
    bool uniformRngHelper(const int* const histo, const int buckets);
    void testSkewedRandomGenerator();
    bool skewedRngHelper(const int* const histo, const int buckets);
    void testTwoTieredRandomGenerator();
    bool twoTieredRngHelper(const int* const histo, const int buckets);
    void testBinomialRandomGenerator();
    bool binomialRngHelper(const int* const histo, const int buckets);
    
    const int countHisto(const int* const histo, const int buckets);
    const int* histogram(const int* const list, const int size, const int buckets);
};

#endif /* RANDOMGENERATORUNITTEST_H */

