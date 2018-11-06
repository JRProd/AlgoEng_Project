/* 
 * File:   main.cpp
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 12:11 PM
 */

#include <cstdlib>

#include "conference/ConferenceConflictDetector.h"
#include "conflicts/ConflictHandler.h"

using namespace std;

int main(int argc, char** argv) {
    const ConferenceConflictParams* params = ConferenceConflictParams::Builder()
            .setSessions(1000)
            ->setAttendees(800)
            ->setSessionsPerAttendee(600)
            ->setDistribution(Dist::Skewed)
            ->setShowOutput(0)
            ->setOutputNewLine(10)
            ->setPBatchSize(10000)
            ->setEBatchSize(100000)
            ->setConflictSizeConstrinat(ConflictSizeConstraint::N2)
            ->build();

    ConferenceConflictDetector conferenceDetector(params);
    
    conferenceDetector.generateConflicts();
    conferenceDetector.handleResults("output.txt");
    
    delete params;
}