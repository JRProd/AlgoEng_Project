/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ColorerUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Nov 12, 2018, 3:23:48 PM
 */

#include "ColorerUnitTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ColorerUnitTest);

ColorerUnitTest::ColorerUnitTest() {
}

ColorerUnitTest::~ColorerUnitTest() {
}

void ColorerUnitTest::setUp() {
}

void ColorerUnitTest::tearDown() {
}

void ColorerUnitTest::testSmallColor() {
    int pArray[10] = {0, 4, 8, 14, 21, 27, 34, 40, 44, 48};
    int eArray[52] = {2, 4, 6, 8, 3, 5, 7, 9, 0, 3, 4, 5, 
                      6, 8, 1, 2, 4, 5, 6, 7, 9, 0, 2, 3, 
                      5, 6, 8, 1, 2, 3, 4, 6, 7, 9, 0, 2, 
                      3, 4, 5, 8, 1, 3, 5, 9, 0, 2, 4, 6,
                      1, 3, 5, 7};
    
    int* peArray[] = {pArray, eArray};
    
    Colorer colorer(new SmallestLastOrdering(10));
    
    colorer.buildVertexList(peArray, 10, 52);
    colorer.color();
    
    std::vector<const Vertex*> vertexList = colorer.getVertexList();
    
    
    int colorList[10];
    int actualList[10] = {0,1,1,0,2,3,4,2,3,4};
    for(int i = 0; i < vertexList.size(); i++) {
        const Vertex* v = vertexList.at(i);
        colorList[i] = v->getColor();
    }
    
    bool assert = assertList(colorList, actualList, 10);
    
    CPPUNIT_ASSERT(assert);
}

void ColorerUnitTest::testLargeColor() {
    int pArray[30] = {0, 9, 23, 32, 46, 55, 64, 73, 87, 103, 
                      112, 121, 135, 151, 165, 174, 183, 192, 201, 217, 
                      244, 226, 244, 244, 244, 244, 235, 244, 244, 244};
    int eArray[244] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 3, 5, 7, 8, 9, 
                       11, 12, 13, 15, 17, 18, 19, 21, 26, 0, 4, 6, 8, 
                       10, 12, 14, 16, 18, 1, 5, 7, 8, 9, 11, 12, 13, 
                       15, 17, 18, 19, 21, 26, 0, 2, 6, 8, 10, 12, 14, 
                       16, 18, 1, 3, 7, 9, 11, 13, 15, 17, 19, 0, 2, 4, 
                       8, 10, 12, 14, 16, 18, 1, 3, 5, 8, 9, 11, 12, 13, 
                       15, 17, 18, 19, 21, 26, 0, 1, 2, 3, 4, 6, 7, 10, 
                       11, 12, 13, 14, 16, 18, 21, 26, 1, 3, 5, 7, 11, 
                       13, 15, 17, 19, 0, 2, 4, 6, 8, 12, 14, 16, 18, 
                       1, 3, 5, 7, 8, 9, 12, 13, 15, 17, 18, 19, 21, 26, 
                       0, 1, 2, 3, 4, 6, 7, 8, 10, 11, 13, 14, 16, 18, 
                       21, 26, 1, 3, 5, 7, 8, 9, 11, 12, 15, 17, 18, 19, 
                       21, 26, 0, 2, 4, 6, 8, 10, 12, 16, 18, 1, 3, 5, 
                       7, 9, 11, 13, 17, 19, 0, 2, 4, 6, 8, 10, 12, 14, 
                       18, 1, 3, 5, 7, 9, 11, 13, 15, 19, 0, 1, 2, 3, 4, 
                       6, 7, 8, 10, 11, 12, 13, 14, 16, 21, 26, 1, 3, 5, 
                       7, 9, 11, 13, 15, 17, 1, 3, 7, 8, 11, 12, 13, 18, 
                       26, 1, 3, 7, 8, 11, 12, 13, 18, 21};
    
    int* peArray[] = {pArray, eArray};
    
    
    Colorer colorer(new SmallestLastOrdering(30));
    
    colorer.buildVertexList(peArray, 30, 244);
    colorer.color();
    
    std::vector<const Vertex*> vertexList = colorer.getVertexList();
    
    
    int colorList[30];
    int actualList[30] = {0,0,1,1,2,4,3,2,4,6,5,3,6,5,7,7,8,8,9,9,0,7,0,0,0,0,8,0,0,0};
    for(int i = 0; i < vertexList.size(); i++) {
        const Vertex* v = vertexList.at(i);
        colorList[i] = v->getColor();
    }
    
    bool assert = assertList(colorList, actualList, 30);
    
    CPPUNIT_ASSERT(assert);
}

bool ColorerUnitTest::assertList(int* l1, int* l2, int size) {
    for(int i = 0; i < size; i++) {
        if(*(l1+i) != *(l2+i)) {
            return false;
        }
    }
    return true;
}


