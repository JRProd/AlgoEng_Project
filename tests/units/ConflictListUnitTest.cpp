/*
 * File:   ConflictListUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Sep 24, 2018, 3:14:49 PM
 */

#include "ConflictListUnitTest.h"

#include "../../utils/MathUtils.h"

#include "../../conflicts/ConflictHandler.h"
#include "../../conflicts/ConflictList.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ConflictListUnitTest);

ConflictListUnitTest::ConflictListUnitTest() {
}

ConflictListUnitTest::~ConflictListUnitTest() {
}

void ConflictListUnitTest::setUp() {
}

void ConflictListUnitTest::tearDown() {
}

void ConflictListUnitTest::testSmallList() {
    std::cout << "###### Starting Small List Test ######" << std::endl;
    int sessionsAvaliable = 10;
    int sessionsAttended = 5;
    
    int pair1[5] = {1,3,5,7,9};
    int pair2[5] = {0,2,4,6,8};
    int pair3[5] = {4,3,5,2,6};
    
    int pArrayValidate[10] = {0, 4, 8, 14, 21, 27, 34, 40, 44, 48};
    
    std::cout << "Creating conflict list" << std::endl;
    ConflictHandler* conflicts = new ConflictList(sessionsAvaliable);
    conflicts->addConflictCount(MathUtils::pairs(sessionsAttended)*3);
    
    for(int i = 0; i < sessionsAttended; i++) {
        for(int j = 0; j < sessionsAttended; j++) {
            if(i != j) {
                conflicts->addConflict(std::make_pair(pair1[i],pair1[j]));
                conflicts->addConflict(std::make_pair(pair2[i],pair2[j]));
                conflicts->addConflict(std::make_pair(pair3[i],pair3[j]));
            }
        }
    }
    
    int** arrays = conflicts->peArray();
    
    std::cout << "Validating pArray" << std::endl;
    bool pValid = validateArrays(pArrayValidate, *(arrays+0), sessionsAvaliable);

    delete[] *(arrays+0);
    delete[] *(arrays+1);
    delete[] arrays;
    delete conflicts;
    
    CPPUNIT_ASSERT(pValid);
}

void ConflictListUnitTest::testLargeList() {
    std::cout << "###### Starting Small List Test ######" << std::endl;
    int sessionsAvaliable = 30;
    int sessionsAttended = 10;
    
    int pair1[10] = {1,3,5,7,9,11,13,15,17,19};
    int pair2[10] = {0,2,4,6,8,10,12,14,16,18};
    int pair3[10] = {18,1,12,8,13,11,21,3,7,26};
    
    int pArrayValidate[30] = {0, 9, 23, 32, 46, 55, 64, 73, 87, 103, 
                              112, 121, 135, 151, 165, 174, 183, 192, 201, 217, 
                              244, 226, 244, 244, 244, 244, 235, 244, 244, 244};
    
    std::cout << "Creating conflict list" << std::endl;
    ConflictHandler* conflicts = new ConflictList(sessionsAvaliable);
    conflicts->addConflictCount(MathUtils::pairs(sessionsAttended)*3);
    
    for(int i = 0; i < sessionsAttended; i++) {
        for(int j = 0; j < sessionsAttended; j++) {
            if(i != j) {
                conflicts->addConflict(std::make_pair(pair1[i],pair1[j]));
                conflicts->addConflict(std::make_pair(pair2[i],pair2[j]));
                conflicts->addConflict(std::make_pair(pair3[i],pair3[j]));
            }
        }
    }
    
    int** arrays = conflicts->peArray();
    
    std::cout << "Validating pArray" << std::endl;
    bool pValid = validateArrays(pArrayValidate, *(arrays+0), sessionsAvaliable);

    delete[] *(arrays+0);
    delete[] *(arrays+1);
    delete[] arrays;
    delete conflicts;
    
    CPPUNIT_ASSERT(pValid);
}

bool ConflictListUnitTest::validateArrays(const int* const list1, const int* const list2, const int size) {
    for(int i = 0; i < size; i++) {
        if(*(list1+i) != *(list2+i)) {
            return false;
        }
    }
    return true;
}

