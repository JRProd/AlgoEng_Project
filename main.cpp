/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 12:11 PM
 */

#include <cstdlib>

#include "conference/ConferenceConflictDetector.h"
#include "conflicts/ConflictHandler.h"
#include "distributions/Distribution.h"

using namespace std;

#include <iostream>
int main(int argc, char** argv) {

    ConferenceConflictDetector test(10000,1000,2000, Dist::Skewed);
    test.selectConflictSize(ConflictSizeConstrinat::N2);
    test.generateConflicts(10);
    std::cout << "Handling results" << std::endl;
    test.handleResults("test.txt");
}

