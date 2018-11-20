/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DegreeListUnitTest.h
 * Author: jake.rowland
 *
 * Created on Nov 7, 2018, 2:23:25 PM
 */

#ifndef COLORORDERINGUNITTEST_H
#define COLORORDERINGUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../coloring/Vertex.h"
#include "../../coloring/SmallestLastOrdering.h"

class ColorOrderingUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ColorOrderingUnitTest);

    CPPUNIT_TEST(testSmall);
    CPPUNIT_TEST(testLarge);
    CPPUNIT_TEST(testSmallColoring);
    CPPUNIT_TEST(testLargeColoring);

    CPPUNIT_TEST_SUITE_END();

public:
    ColorOrderingUnitTest();
    virtual ~ColorOrderingUnitTest();
    void setUp();
    void tearDown();
    
    void printList(std::vector<Vertex*> v);
    bool assertList(std::vector<Vertex*> v, int* list, int size);

private:
    void testSmall();
    void testLarge();
    void testSmallColoring();
    void testLargeColoring();
};

#endif /* DEGREELISTUNITTEST_H */

