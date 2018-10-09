/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConglictGraphUnitTest.h
 * Author: jake.rowland
 *
 * Created on Sep 17, 2018, 11:07:01 AM
 */

#ifndef CONGLICTGRAPHUNITTEST_H
#define CONGLICTGRAPHUNITTEST_H

#include <iostream>

#include <cppunit/extensions/HelperMacros.h>

class ConflictGraphUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ConflictGraphUnitTest);

    CPPUNIT_TEST(testSmallGraph);
    CPPUNIT_TEST(testLargeGraph);

    CPPUNIT_TEST_SUITE_END();

public:
    ConflictGraphUnitTest();
    virtual ~ConflictGraphUnitTest();
    void setUp();
    void tearDown();

private:
    void testSmallGraph();
    void testLargeGraph();
    
    bool validateArrays(const int* const list1, const int* const list2, const int size);
    void printArray(const int* const list, const int size);
};

#endif /* CONGLICTGRAPHUNITTEST_H */

