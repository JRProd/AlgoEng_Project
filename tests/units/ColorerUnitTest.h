/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ColorerUnitTest.h
 * Author: jake.rowland
 *
 * Created on Nov 12, 2018, 3:23:48 PM
 */

#ifndef COLORERUNITTEST_H
#define COLORERUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../coloring/ColorOrderingInterface.h"
#include "../../coloring/Colorer.h"
#include "../../coloring/InOrderOrdering.h"
#include "../../coloring/RandomOrdering.h"
#include "../../coloring/SmallestLastOrdering.h"

class ColorerUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ColorerUnitTest);

    CPPUNIT_TEST(testSmallColor);
    CPPUNIT_TEST(testLargeColor);

    CPPUNIT_TEST_SUITE_END();

public:
    ColorerUnitTest();
    virtual ~ColorerUnitTest();
    void setUp();
    void tearDown();

private:
    void testSmallColor();
    void testLargeColor();
    
    bool assertList(int* l1, int* l2, int size);
};

#endif /* COLORERUNITTEST_H */

