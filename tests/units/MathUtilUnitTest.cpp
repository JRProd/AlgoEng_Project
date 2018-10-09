/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MathUtilUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Sep 17, 2018, 1:45:12 PM
 */

#include "MathUtilUnitTest.h"

#include "../../utils/MathUtils.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MathUtilUnitTest);

MathUtilUnitTest::MathUtilUnitTest() {
}

MathUtilUnitTest::~MathUtilUnitTest() {
}

void MathUtilUnitTest::setUp() {
}

void MathUtilUnitTest::tearDown() {
}

void MathUtilUnitTest::testFactorial1() {
    int number = 5;
    int factorial = MathUtils::factorial(number); 
            
    CPPUNIT_ASSERT(factorial == 120);
}

void MathUtilUnitTest::testFactorial2() {
    int number = 10;
    unsigned long factorial = MathUtils::factorial(number);
    
    CPPUNIT_ASSERT(factorial == 3628800);
}

void MathUtilUnitTest::testFactorial3() {
    int number = 13;
    unsigned long factorial = MathUtils::factorial(number);
    
    CPPUNIT_ASSERT(factorial == 6227020800L);
}

void MathUtilUnitTest::testChoose1() {
    int n = 4;
    int k = 1;
    unsigned long choosen = MathUtils::choose(n,k);
    
    CPPUNIT_ASSERT(choosen == 4);
}

void MathUtilUnitTest::testChoose2() {
    int n = 10;
    int k = 4;
    unsigned long choosen = MathUtils::choose(n,k);
    
    CPPUNIT_ASSERT(choosen == 210);
}

void MathUtilUnitTest::testChoose3() {
    int n = 50;
    int k = 10;
    unsigned long choosen = MathUtils::choose(n,k);
    
    CPPUNIT_ASSERT(choosen == 10272278170);
}

void MathUtilUnitTest::testPair1() {
    int n = 2;
    
    unsigned long pairs = MathUtils::pairs(n);
    
    CPPUNIT_ASSERT(pairs == 1);
}

void MathUtilUnitTest::testPair2() {
    int n = 10;
    
    unsigned long pairs = MathUtils::pairs(n);
    
    CPPUNIT_ASSERT(pairs == 45);
}

void MathUtilUnitTest::testPair3() {
    int n = 10000;
    
    unsigned long pairs = MathUtils::pairs(n);
    
    CPPUNIT_ASSERT(pairs == 49995000);
}



