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
#include "distributions/UniformDistribution.h"

using namespace std;

int main(int argc, char** argv) {
    std::cout << "Starting" << std::endl;
    
    ConferenceConflictParams::Builder* paramBuilders[2] = {
        ConferenceConflictParams::Builder()
                .setDistribution(Dist::Uniform)
                ->setShowOutput(0)
                ->setOutputNewLine(10)
                ->setPBatchSize(10000)
                ->setEBatchSize(100000)
                ->setConflictSizeConstrinat(ConflictSizeConstraint::M),
        ConferenceConflictParams::Builder()
                .setDistribution(Dist::Skewed)
                ->setShowOutput(0)
                ->setOutputNewLine(10)
                ->setPBatchSize(10000)
                ->setEBatchSize(100000)
                ->setConflictSizeConstrinat(ConflictSizeConstraint::M)
    };
    
    int upperAttendee[6] = {10, 50, 100, 500, 1000, 5000};
    
    // I believe this will be based on the O(distro)
    int upperSessionsHigher[6] = {500, 1000, 2000, 3000, 4000, 5000};
    int upperSessionsLower[6] = {50, 100, 200, 300, 400, 500};
    
    for(int i = 0; i < 2; i ++) {
        auto builder = paramBuilders[i];
        int* upperSessions;
        if(i % 2 == 1) {
            upperSessions = upperSessionsLower;
        } else {
            upperSessions = upperSessionsHigher;
        }
        for(int attendee: upperAttendee){
            std::cout << attendee << ", ";
            for(int j = 0; j < 6; j++) {
                int session = *(upperSessions+j);
                const ConferenceConflictParams* params = builder
                    ->setSessions(10000)
                    ->setAttendees(attendee)
                    ->setSessionsPerAttendee(session)
                    ->build();
                
                if(session > 1000 &&
                        (params->getDistribution() == Dist::Skewed ||
                        params->getDistribution() == Dist::Binomial)) {
                    break;
                }

                ConferenceConflictDetector conferenceDetector(params);

                
                std::chrono::time_point<std::chrono::system_clock> generate;
                generate = std::chrono::system_clock::now();

                conferenceDetector.generateConflicts();

                auto end = std::chrono::system_clock::now() - generate;
                long duration = 
                    std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
                std::cout << duration << ", ";
            }
            std::cout << std::endl;
        }
    }
    
    
    // Uniform checking
    std::chrono::time_point<std::chrono::system_clock> generate;
    generate = std::chrono::system_clock::now();
    
    //unif->generateSessions(upper);
    
    std::cout << "         #### Finish Uniform in ";
    auto end = std::chrono::system_clock::now() - generate;
    long duration = 
        std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
    std::cout << duration << "ms" << std::endl;
    
    // Skewed checking
    generate = std::chrono::system_clock::now();
    
    //skew->generateSessions(upper);
    
    std::cout << "         #### Finish Skewed in ";
    end = std::chrono::system_clock::now() - generate;
    duration = 
        std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
    std::cout << duration << "ms" << std::endl;

    // Tier checking
    generate = std::chrono::system_clock::now();
    
    //tier->generateSessions(upper);
    
    
    std::cout << "         #### Finish Tier in ";
    end = std::chrono::system_clock::now() - generate;
    duration = 
        std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
    std::cout << duration << "ms" << std::endl;

    
    // Binomial checking
    generate = std::chrono::system_clock::now();
     
    //bino->generateSessions(upper);
    
    std::cout << "         #### Finish Binomial checking in ";
    end = std::chrono::system_clock::now() - generate;
    duration = 
        std::chrono::duration_cast<std::chrono::milliseconds>(end).count();
    std::cout << duration << "ms" << std::endl;
    
/*
    
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
            ->build();

    ConferenceConflictDetector conferenceDetector(params);
    
    conferenceDetector.generateConflicts();
    conferenceDetector.handleResults("test.txt");
 * 
    delete params;
     */
}

