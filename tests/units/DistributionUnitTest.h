/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DistributionUnitTest.h
 * Author: jake.rowland
 *
 * Created on Sep 11, 2018, 12:18:20 AM
 */

#ifndef DISTRIBUTIONUNITTEST_H
#define DISTRIBUTIONUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

class DistributionUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(DistributionUnitTest);

    CPPUNIT_TEST(testUniformDistribution);
    CPPUNIT_TEST(testSkewedDistribution);
    CPPUNIT_TEST(testTwoTieredDistribution);
    CPPUNIT_TEST(testBinomialDistribution);

    CPPUNIT_TEST_SUITE_END();

public:
    DistributionUnitTest();
    void setUp();
    void tearDown();

private:
    void testUniformDistribution();
    void testSkewedDistribution();
    void testTwoTieredDistribution();
    void testBinomialDistribution();
    
    void printSet(std::set<int> set);
};

#endif /* DISTRIBUTIONUNITTEST_H */

