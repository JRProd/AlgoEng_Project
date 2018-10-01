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
    
    const ConferenceConflictParams* params = ConferenceConflictParams::Builder()
            .setSessions(10000)
            ->setAttendees(10)
            ->setSessionsPerAttendee(5000)
            ->setDistribution(Dist::Tiered)
            ->setShowOutput(0)
            ->setOutputNewLine(10)
            ->setPBatchSize(10000)
            ->setEBatchSize(100000)
            ->setConflictSizeConstrinat(ConflictSizeConstrinat::N2)
            ->setDebugMode(3)
            ->build();

    ConferenceConflictDetector conferenceDetector(params);
    
    conferenceDetector.generateConflicts();
    // conferenceDetector.handleResults("test.txt");
    
    delete params;
}

