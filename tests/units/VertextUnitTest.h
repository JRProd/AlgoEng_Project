/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VertextUnitTest.h
 * Author: jake.rowland
 *
 * Created on Nov 7, 2018, 11:37:23 AM
 */

#ifndef VERTEXTUNITTEST_H
#define VERTEXTUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../coloring/Vertex.h"

class VertextUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(VertextUnitTest);

    CPPUNIT_TEST(testVertexSmall);
    CPPUNIT_TEST(testVertexLarge);
    CPPUNIT_TEST(testVertexNoCollisions);
    CPPUNIT_TEST(testVertexSmallColoring);
    CPPUNIT_TEST(testVertexLargeColoring);
    CPPUNIT_TEST(testVertexNoCollisionsColoring);

    CPPUNIT_TEST_SUITE_END();

public:
    VertextUnitTest();
    virtual ~VertextUnitTest();
    void setUp();
    void tearDown();

private:
    void testVertexSmall();
    void testVertexLarge();
    void testVertexNoCollisions();
    
    void testVertexSmallColoring();
    void testVertexLargeColoring();
    void testVertexNoCollisionsColoring();
};

#endif /* VERTEXTUNITTEST_H */

