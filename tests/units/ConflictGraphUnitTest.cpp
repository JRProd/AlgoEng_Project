/*
 * File:   ConglictGraphUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Sep 17, 2018, 11:07:01 AM
 */

#include "ConflictGraphUnitTest.h"

#include "../../utils/MathUtils.h"

#include "../../conflicts/ConflictHandler.h"
#include "../../conflicts/ConflictGraph.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ConflictGraphUnitTest);

ConflictGraphUnitTest::ConflictGraphUnitTest() {
}

ConflictGraphUnitTest::~ConflictGraphUnitTest() {
}

void ConflictGraphUnitTest::setUp() {
}

void ConflictGraphUnitTest::tearDown() {
}

void ConflictGraphUnitTest::testSmallGraph() {
    std::cout << "###### Starting Small Graph Test ######" << std::endl;
    int sessionsAvaliable = 10;
    int sessionsAttended = 5;
    
    int pair1[5] = {1,3,5,7,9};
    int pair2[5] = {0,2,4,6,8};
    int pair3[5] = {4,3,5,2,6};
    
    int pArrayValidate[10] = {0, 4, 8, 14, 21, 27, 34, 40, 44, 48};
    int eArrayValidate[52] = {2, 4, 6, 8, 3, 5, 7, 9, 0, 3, 4, 5, 
                              6, 8, 1, 2, 4, 5, 6, 7, 9, 0, 2, 3, 
                              5, 6, 8, 1, 2, 3, 4, 6, 7, 9, 0, 2, 
                              3, 4, 5, 8, 1, 3, 5, 9, 0, 2, 4, 6,
                              1, 3, 5, 7};
    
    std::cout << "Creating conflict graph" << std::endl;
    ConflictHandler* conflicts = new ConflictGraph(sessionsAvaliable);
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
    
    std::cout << "Validating arrays" << std::endl;
    bool pValid = validateArrays(pArrayValidate, *(arrays+0), sessionsAvaliable);
    bool eValid = validateArrays(eArrayValidate, *(arrays+1), conflicts->getUniqueConflictCount());

    delete[] *(arrays+0);
    delete[] *(arrays+1);
    delete[] arrays;
    delete conflicts;
    
    CPPUNIT_ASSERT(pValid && eValid);
}

void ConflictGraphUnitTest::testLargeGraph() {
    std::cout << "###### Starting Large Graph Test ######" << std::endl;
    int sessionsAvaliable = 30;
    int sessionsAttended = 10;
    
    int pair1[10] = {1,3,5,7,9,11,13,15,17,19};
    int pair2[10] = {0,2,4,6,8,10,12,14,16,18};
    int pair3[10] = {18,1,12,8,13,11,21,3,7,26};
    
    int pArrayValidate[30] = {0, 9, 23, 32, 46, 55, 64, 73, 87, 103, 
                              112, 121, 135, 151, 165, 174, 183, 192, 201, 217, 
                              244, 226, 244, 244, 244, 244, 235, 244, 244, 244};
    int eArrayValidate[244] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 3, 5, 7, 8, 9, 
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
    
    std::cout << "Creating conflict graph" << std::endl;
    ConflictHandler* conflicts = new ConflictGraph(sessionsAvaliable);
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
    
    std::cout << "Validating arrays" << std::endl;
    bool pValid = validateArrays(pArrayValidate, *(arrays+0), sessionsAvaliable);
    bool eValid = validateArrays(eArrayValidate, *(arrays+1), conflicts->getUniqueConflictCount());

    delete[] *(arrays+0);
    delete[] *(arrays+1);
    delete[] arrays;
    delete conflicts;
    
    CPPUNIT_ASSERT(pValid && eValid);
}

#include "../../coloring/ColorOrderingInterface.h"
#include "../../coloring/SmallestLastOrdering.h"
void ConflictGraphUnitTest::testBuildSmallGraph() {
    int pArray[10] = {0, 4, 8, 14, 21, 27, 34, 40, 44, 48};
    int eArray[52] = {2, 4, 6, 8, 3, 5, 7, 9, 0, 3, 4, 5, 
                      6, 8, 1, 2, 4, 5, 6, 7, 9, 0, 2, 3, 
                      5, 6, 8, 1, 2, 3, 4, 6, 7, 9, 0, 2, 
                      3, 4, 5, 8, 1, 3, 5, 9, 0, 2, 4, 6,
                      1, 3, 5, 7};
    
    int* peArray[2] = {pArray, eArray};
    
    ConflictGraph* conflicts = new ConflictGraph(peArray, 10, 52);
}

void ConflictGraphUnitTest::testBuildLargeGraph() {
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
    
    int* peArray[2] = {pArray, eArray};
    
    ConflictGraph* conflicts = new ConflictGraph(peArray, 30, 244);

}


bool ConflictGraphUnitTest::validateArrays(const int* const list1, const int* const list2, const int size) {
    for(int i = 0; i < size; i++) {
        if(*(list1+i) != *(list2+i)) {
            return false;
        }
    }
    return true;
}




