/* 
 * File:   ConflictSet.cpp
 * Author: jake.rowland
 * 
 * Created on September 15, 2018, 6:06 PM
 */

#include "ConflictHandler.h"

ConflictHandler::~ConflictHandler() {   
}

int ConflictHandler::getUniqueConflictCount() {
    return uniqueConflictCount;
}

int ConflictHandler::getSizeOfEArray() {
    return uniqueConflictCount*2;
}

void ConflictHandler::addConflictCount(unsigned long conflict) {
    conflictCount += conflict;
}

unsigned long ConflictHandler::getConflictCount() {
    return conflictCount;
}

bool ConflictHandler::isAtMaxConflicts() {
    return maxConflict == uniqueConflictCount;
}