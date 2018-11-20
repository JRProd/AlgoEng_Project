/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DegreeListUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Nov 7, 2018, 2:23:25 PM
 */

#include "ColorOrderingUnitTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ColorOrderingUnitTest);

ColorOrderingUnitTest::ColorOrderingUnitTest() {
}

ColorOrderingUnitTest::~ColorOrderingUnitTest() {
}

void ColorOrderingUnitTest::setUp() {
}

void ColorOrderingUnitTest::tearDown() {
}

#include <iostream>
void ColorOrderingUnitTest::printList(std::vector<Vertex*> v) {
    for(Vertex* i : v) {
        std::cout << i->getSession() << " ";
    }
    std::cout << std::endl;
}

bool ColorOrderingUnitTest::assertList(std::vector<Vertex*> v, int* list, int size) {
    for(int i = 0; i < size; i++) {
        if(v.at(i)->getSession() != *(list+i)) {
            return false;
        }
    }
    
    return true;
}


void ColorOrderingUnitTest::testSmall() {
    ColorOrderingInterface* degreeList = new SmallestLastOrdering(2);
    
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
    
    degreeList->addVertex(&v0);
    degreeList->addVertex(&v1);
    degreeList->addVertex(&v2);
    degreeList->addVertex(&v3);
    
    std::vector<Vertex*> list = degreeList->getOrdering();
    
    int testList[] = {2,3,1,0};
    bool assertSmall = assertList(list, testList, 4);
            
    CPPUNIT_ASSERT(assertSmall);
}

void ColorOrderingUnitTest::testLarge() {
    ColorOrderingInterface* degreeList = new SmallestLastOrdering(4);
    
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
    
    degreeList->addVertex(&v0);
    degreeList->addVertex(&v1);
    degreeList->addVertex(&v2);
    degreeList->addVertex(&v3);
    degreeList->addVertex(&v4);
    degreeList->addVertex(&v5);
    degreeList->addVertex(&v6);
    degreeList->addVertex(&v7);
    degreeList->addVertex(&v8);
    degreeList->addVertex(&v9);
    degreeList->addVertex(&v10);
    degreeList->addVertex(&v11);
    
    std::vector<Vertex*> list = degreeList->getOrdering();
    
    int testList[] = {8, 11, 9, 1, 0, 4, 5, 10, 6, 7, 3, 2};
    bool assertLarge = assertList(list, testList, 12);
    
    CPPUNIT_ASSERT(assertLarge);
}


void ColorOrderingUnitTest::testSmallColoring() {
    ColorOrderingInterface* degreeList = new SmallestLastOrdering(2);
    
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
    
    degreeList->addVertex(&v0);
    degreeList->addVertex(&v1);
    degreeList->addVertex(&v2);
    degreeList->addVertex(&v3);
    
    std::vector<Vertex*> list = degreeList->getOrdering();
    
    for(int i = list.size()-1; i >= 0; i--) {
        list.at(i)->setColor();
    }
            
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

void ColorOrderingUnitTest::testLargeColoring() {
    ColorOrderingInterface* degreeList = new SmallestLastOrdering(4);
    
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
    
    degreeList->addVertex(&v0);
    degreeList->addVertex(&v1);
    degreeList->addVertex(&v2);
    degreeList->addVertex(&v3);
    degreeList->addVertex(&v4);
    degreeList->addVertex(&v5);
    degreeList->addVertex(&v6);
    degreeList->addVertex(&v7);
    degreeList->addVertex(&v8);
    degreeList->addVertex(&v9);
    degreeList->addVertex(&v10);
    degreeList->addVertex(&v11);
    
    std::vector<Vertex*> list = degreeList->getOrdering();
    
    for(int i = list.size()-1; i >= 0; i--) {
        list.at(i)->setColor();
    }
    
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
    
    if(v0.getColor() == 1) assertV0 = true;
    if(v1.getColor() == 0) assertV1 = true;
    if(v2.getColor() == 0) assertV2 = true;
    if(v3.getColor() == 1) assertV3 = true;
    if(v4.getColor() == 0) assertV4 = true;
    if(v5.getColor() == 1) assertV5 = true;
    if(v6.getColor() == 1) assertV6 = true;
    if(v7.getColor() == 0) assertV7 = true;
    if(v8.getColor() == 0) assertV8 = true;
    if(v9.getColor() == 1) assertV9 = true;
    if(v10.getColor() == 0) assertV10 = true;
    if(v11.getColor() == 0) assertV11 = true;
    
    CPPUNIT_ASSERT(assertV0 && assertV1 && assertV2 && assertV3 &&
                   assertV4 && assertV5 && assertV6 && assertV7 &&
                   assertV8 && assertV9 && assertV10 && assertV11); 
}

