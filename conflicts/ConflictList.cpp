/* 
 * File:   ConflictList.cpp
 * Author: jake.rowland
 * 
 * Created on September 15, 2018, 7:19 PM
 */

#include "ConflictList.h"

ConflictList::ConflictList(int size) {
    if(size < 1) {
        throw std::invalid_argument("ConflictList: Size must be positive");
    }
    N = size;
    conflictCount = 0;
    uniqueConflictCount = 0;
    
    maxConflict = MathUtils::pairs(size);
}

ConflictList::~ConflictList() {
}

int** ConflictList::peArray() {
    int** peArrays = new int*[2];
    int* pArray = new int[N];
    int* eArray = new int[uniqueConflictCount*2];
    
    // For each session
    int eArrayLoc = 0;
    for(int i = 0; i < N; i++ ) {
        *(pArray+i) = eArrayLoc;
        
        for(std::pair<int,int> pair: pairs) {
            if(pair.first == i) {
                *(eArray+eArrayLoc) = pair.second;
                eArrayLoc++;
            }
        }
        
        if(*(pArray+i) == eArrayLoc) {
            *(pArray+i) = uniqueConflictCount*2;
        }
    }
    
    *(peArrays+0) = pArray;
    *(peArrays+1) = eArray;
    
    return peArrays;
}

void ConflictList::addConflict(std::pair<int, int> pair) {
    if(pair.first == pair.second) {
        return;
    }
    
    if(!isInSet(pair)) {
        
        pairs.insert(pair);
        
        std::pair <int,int> flipedPair = std::make_pair(
                pair.second, 
                pair.first);
        
        pairs.insert(flipedPair);
        
        uniqueConflictCount++;
    }
}

ConflictSizeConstrinat ConflictList::whatSize() {
    return ConflictSizeConstrinat::M;
}

bool ConflictList::isInSet(std::pair<int, int> pair) {
        if(pairs.find(pair) == pairs.end()) {
            return false;
        }
        return true;
}