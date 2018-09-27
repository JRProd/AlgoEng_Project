/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MathUtilUnitTest.h
 * Author: jake.rowland
 *
 * Created on Sep 17, 2018, 1:45:12 PM
 */

#ifndef MATHUTILUNITTEST_H
#define MATHUTILUNITTEST_H

#include <iostream>

#include <cppunit/extensions/HelperMacros.h>

class MathUtilUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MathUtilUnitTest);

    CPPUNIT_TEST(testFactorial1);
    CPPUNIT_TEST(testFactorial2);
    CPPUNIT_TEST(testFactorial3);
    CPPUNIT_TEST(testPartialFactorial1);
    CPPUNIT_TEST(testPartialFactorial2);
    CPPUNIT_TEST(testPartialFactorial3);
    CPPUNIT_TEST(testChoose1);
    CPPUNIT_TEST(testChoose2);
    CPPUNIT_TEST(testChoose3);
    CPPUNIT_TEST(testPair1);
    CPPUNIT_TEST(testPair2);
    CPPUNIT_TEST(testPair3);

    CPPUNIT_TEST_SUITE_END();

public:
    MathUtilUnitTest();
    virtual ~MathUtilUnitTest();
    void setUp();
    void tearDown();

private:
    void testFactorial1();
    void testFactorial2();
    void testFactorial3();
    void testPartialFactorial1();
    void testPartialFactorial2();
    void testPartialFactorial3();
    void testChoose1();
    void testChoose2();
    void testChoose3();
    void testPair1();
    void testPair2();
    void testPair3();
};

#endif /* MATHUTILUNITTEST_H */

