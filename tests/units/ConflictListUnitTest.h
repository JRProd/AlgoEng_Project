/*
 * File:   ConflictListUnitTest.h
 * Author: jake.rowland
 *
 * Created on Sep 24, 2018, 3:14:49 PM
 */

#ifndef CONFLICTLISTUNITTEST_H
#define CONFLICTLISTUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

class ConflictListUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ConflictListUnitTest);

    CPPUNIT_TEST(testSmallList);
    CPPUNIT_TEST(testLargeList);

    CPPUNIT_TEST_SUITE_END();

public:
    ConflictListUnitTest();
    virtual ~ConflictListUnitTest();
    void setUp();
    void tearDown();

private:
    void testSmallList();
    void testLargeList();
    
    bool validateArrays(const int* const list1, const int* const list2, const int size);
};

#endif /* CONFLICTLISTUNITTEST_H */

