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
#include<string>

#include "coloring/ConferenceScheduler.h"
#include "conference/ConferenceConflictDetector.h"

using namespace std;

int main(int argc, char** argv) {
    int css[10] = {10,25,50,100,250,500,1000,2500,5000,10000};
    std::string csf[10] = {"test10_FC.txt", "test25_FC.txt", "test50_FC.txt", "test100_FC.txt", "test250_FC.txt", "test500_FC.txt", "test1000_FC.txt", "test2500_FC.txt", "test5000_FC.txt", "test10000_FC.txt"};
    
//    for(int i = 0; i < 7; i++) {
//        ConferenceConflictDetector cd(ConferenceConflictParams::Builder()
//                .setSessions(css[i])
//                ->setAttendees(1)
//                ->setSessionsPerAttendee(css[i])->build());
//                
//        cd.generateConflicts();
//        cd.handleResults(csf[i]);
//    }
    
    std::string str = "test1000_FC.txt";
        std::cout << "Running " << str <<std::endl;
        ConferenceScheduler cs(str);

        cs.chooseOrder(ColorOrdering::SLO);

        cs.color();

        //cs.displaySchedule(false);
}

