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

int main(int argc, char** argv) {
    
    int debugMode = 0;
    
    const ConferenceConflictParams* params = ConferenceConflictParams::Builder()
            .setSessions(1000)
            ->setAttendees(1000)
            ->setSessionsPerAttendee(100)
            ->setDistribution(Dist::Skewed)
            ->setShowOutput(0)
            ->setOutputNewLine(10)
            ->setPBatchSize(10000)
            ->setEBatchSize(100000)
            ->setConflictSizeConstrinat(ConflictSizeConstrinat::N2)
            ->setDebugMode(debugMode)
            ->build();

    ConferenceConflictDetector conferenceDetector(params);
    
    std::chrono::time_point<std::chrono::system_clock> start;
    if(debugMode >= 0) {
        std::cout << "main.cpp #### Starting" << std::endl;
        start = std::chrono::system_clock::now();
    }
    conferenceDetector.generateConflicts();
    // conferenceDetector.handleResults("test.txt");
    
    if(debugMode >= 0) {
        std::cout << "main.cpp #### Finished in ";
        auto end = std::chrono::system_clock::now() - start;
        long duration = 
            std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
        std::cout << duration << "ms" << std::endl;
    }
    
    delete params;
}

