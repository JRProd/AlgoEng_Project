/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VertextUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Nov 7, 2018, 11:37:23 AM
 */

#include "VertextUnitTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(VertextUnitTest);

VertextUnitTest::VertextUnitTest() {
}

VertextUnitTest::~VertextUnitTest() {
}

void VertextUnitTest::setUp() {
}

void VertextUnitTest::tearDown() {
}

void VertextUnitTest::testVertexSmall() {
    Vertex v0(0); // 0 -> 1,3
    Vertex v1(1); // 1 -> 0,3
    Vertex v2(2); // 2 -> 
    Vertex v3(3); // 3 -> 0,1
    
    v0.addConflict(&v1);
    v0.addConflict(&v3);
    
    v1.addConflict(&v0);
    v1.addConflict(&v3);
    
    v3.addConflict(&v0);
    v3.addConflict(&v1);
    
    bool assertV0 = false;
    bool assertV1 = false;
    bool assertV2 = false;
    bool assertV3 = false;
    
    if(v0.getDegree() == 2) assertV0 = true;
    if(v1.getDegree() == 2) assertV1 = true;
    if(v2.getDegree() == 0) assertV2 = true;
    if(v3.getDegree() == 2) assertV3 = true;
    
    CPPUNIT_ASSERT(assertV0 && assertV1 && assertV2 && assertV3); 
}

#include <iostream>
void VertextUnitTest::testVertexLarge() {
    Vertex v0(0);   //  0 -> 1,4
    Vertex v1(1);   //  1 -> 0
    Vertex v2(2);   //  2 -> 3,5,6
    Vertex v3(3);   //  3 -> 2,7
    Vertex v4(4);   //  4 -> 0,5
    Vertex v5(5);   //  5 -> 2,4,10
    Vertex v6(6);   //  6 -> 2,7,10,11
    Vertex v7(7);   //  7 -> 3,6
    Vertex v8(8);   //  8 -> 
    Vertex v9(9);   //  9 -> 10
    Vertex v10(10); // 10 -> 5,6,9
    Vertex v11(11); // 11 -> 6
    
    v0.addConflict(&v1);
    v0.addConflict(&v4);
    
    v1.addConflict(&v0);
    
    v2.addConflict(&v3);
    v2.addConflict(&v5);
    v2.addConflict(&v6);
    
    v3.addConflict(&v2);
    v3.addConflict(&v7);
    
    v4.addConflict(&v0);
    v4.addConflict(&v5);
    
    v5.addConflict(&v2);
    v5.addConflict(&v4);
    v5.addConflict(&v10);
    
    v6.addConflict(&v2);
    v6.addConflict(&v7);
    v6.addConflict(&v10);
    v6.addConflict(&v11);
    
    v7.addConflict(&v3);
    v7.addConflict(&v6);
    
    
    
    v9.addConflict(&v10);
    
    v10.addConflict(&v5);
    v10.addConflict(&v6);
    v10.addConflict(&v9);
    
    v11.addConflict(&v6);
    
    bool assertV0 = false;
    bool assertV1 = false;
    bool assertV2 = false;
    bool assertV3 = false;
    bool assertV4 = false;
    bool assertV5 = false;
    bool assertV6 = false;
    bool assertV7 = false;
    bool assertV8 = false;
    bool assertV9 = false;
    bool assertV10 = false;
    bool assertV11 = false;
    
    if(v0.getDegree() == 2) assertV0 = true;
    if(v1.getDegree() == 1) assertV1 = true;
    if(v2.getDegree() == 3) assertV2 = true;
    if(v3.getDegree() == 2) assertV3 = true;
    if(v4.getDegree() == 2) assertV4 = true;
    if(v5.getDegree() == 3) assertV5 = true;
    if(v6.getDegree() == 4) assertV6 = true;
    if(v7.getDegree() == 2) assertV7 = true;
    if(v8.getDegree() == 0) assertV8 = true;
    if(v9.getDegree() == 1) assertV9 = true;
    if(v10.getDegree() == 3) assertV10 = true;
    if(v11.getDegree() == 1) assertV11 = true;
    
    CPPUNIT_ASSERT(assertV0 && assertV1 && assertV2 && assertV3 &&
                   assertV4 && assertV5 && assertV6 && assertV7 &&
                   assertV8 && assertV9 && assertV10 && assertV11); 
}

void VertextUnitTest::testVertexNoCollisions() {
    Vertex v0(0);
    
    bool assertV0 = false;
    
    if(v0.getDegree() == 0) assertV0 = true;
    
    CPPUNIT_ASSERT(assertV0);
}

void VertextUnitTest::testVertexSmallColoring() {
    Vertex v0(0); // 0 -> 1,3
    Vertex v1(1); // 1 -> 0,3
    Vertex v2(2); // 2 -> 
    Vertex v3(3); // 3 -> 0,1
    
    v0.addConflict(&v1);
    v0.addConflict(&v3);
    
    v1.addConflict(&v0);
    v1.addConflict(&v3);
    
    v3.addConflict(&v0);
    v3.addConflict(&v1);
    
    v0.setColor();
    v1.setColor();
    v2.setColor();
    v3.setColor();
    
    bool assertV0 = false;
    bool assertV1 = false;
    bool assertV2 = false;
    bool assertV3 = false;
        
    if(v0.getColor() == 0) assertV0 = true;
    if(v1.getColor() == 1) assertV1 = true;
    if(v2.getColor() == 0) assertV2 = true;
    if(v3.getColor() == 2) assertV3 = true;
    
    CPPUNIT_ASSERT(assertV0 && assertV1 && assertV2 && assertV3);
}

void VertextUnitTest::testVertexLargeColoring() {
    Vertex v0(0);   //  0 -> 1,4
    Vertex v1(1);   //  1 -> 0
    Vertex v2(2);   //  2 -> 3,5,6
    Vertex v3(3);   //  3 -> 2,7
    Vertex v4(4);   //  4 -> 0,5
    Vertex v5(5);   //  5 -> 2,4,10
    Vertex v6(6);   //  6 -> 2,7,10,11
    Vertex v7(7);   //  7 -> 3,6
    Vertex v8(8);   //  8 -> 
    Vertex v9(9);   //  9 -> 10
    Vertex v10(10); // 10 -> 5,6,9
    Vertex v11(11); // 11 -> 6
    
    v0.addConflict(&v1);
    v0.addConflict(&v4);
    
    v1.addConflict(&v0);
    
    v2.addConflict(&v3);
    v2.addConflict(&v5);
    v2.addConflict(&v6);
    
    v3.addConflict(&v2);
    v3.addConflict(&v7);
    
    v4.addConflict(&v0);
    v4.addConflict(&v5);
    
    v5.addConflict(&v2);
    v5.addConflict(&v4);
    v5.addConflict(&v10);
    
    v6.addConflict(&v2);
    v6.addConflict(&v7);
    v6.addConflict(&v10);
    v6.addConflict(&v11);
    
    v7.addConflict(&v3);
    v7.addConflict(&v6);
    
    
    
    v9.addConflict(&v10);
    
    v10.addConflict(&v5);
    v10.addConflict(&v6);
    v10.addConflict(&v9);
    
    v11.addConflict(&v6);
    
    v0.setColor();
    v1.setColor();
    v2.setColor();
    v3.setColor();
    v4.setColor();
    v5.setColor();
    v6.setColor();
    v7.setColor();
    v8.setColor();
    v9.setColor();
    v10.setColor();
    v11.setColor();
    
    bool assertV0 = false;
    bool assertV1 = false;
    bool assertV2 = false;
    bool assertV3 = false;
    bool assertV4 = false;
    bool assertV5 = false;
    bool assertV6 = false;
    bool assertV7 = false;
    bool assertV8 = false;
    bool assertV9 = false;
    bool assertV10 = false;
    bool assertV11 = false;
    
    if(v0.getColor() == 0) assertV0 = true;
    if(v1.getColor() == 1) assertV1 = true;
    if(v2.getColor() == 0) assertV2 = true;
    if(v3.getColor() == 1) assertV3 = true;
    if(v4.getColor() == 1) assertV4 = true;
    if(v5.getColor() == 2) assertV5 = true;
    if(v6.getColor() == 1) assertV6 = true;
    if(v7.getColor() == 0) assertV7 = true;
    if(v8.getColor() == 0) assertV8 = true;
    if(v9.getColor() == 0) assertV9 = true;
    if(v10.getColor() == 3) assertV10 = true;
    if(v11.getColor() == 0) assertV11 = true;
    
    CPPUNIT_ASSERT(assertV0 && assertV1 && assertV2 && assertV3 &&
                   assertV4 && assertV5 && assertV6 && assertV7 &&
                   assertV8 && assertV9 && assertV10 && assertV11); 
}

void VertextUnitTest::testVertexNoCollisionsColoring() {
    Vertex v0(0);
    
    v0.setColor();
    
    bool assertV0 = false;
    
    if(v0.getColor() == 0) assertV0 = true;
    
    CPPUNIT_ASSERT(assertV0);
}
