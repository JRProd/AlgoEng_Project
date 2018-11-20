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

#include "coloring/ConferenceScheduler.h"
#include "conference/ConferenceConflictDetector.h"

using namespace std;

int main(int argc, char** argv) {

    ConferenceScheduler cs("largeTest.txt");
    
    cs.chooseOrder(ColorOrdering::SLO);
    
    cs.color();
    
    cs.displaySchedule(false);
}

