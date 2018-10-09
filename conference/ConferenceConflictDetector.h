/* 
 * File:   ConferenceConflictDetector.h
 * Author: jake.rowland
 *
 * Created on September 25, 2018, 9:47 AM
 */

#ifndef CONFERENCECONFLICTDETECTOR_H
#define CONFERENCECONFLICTDETECTOR_H

#include <iostream>
#include <chrono>

#include "ConferenceConflictParams.h"

#include "../conflicts/ConflictHandler.h"
#include "../conflicts//ConflictGraph.h"
#include "../conflicts/ConflictList.h"

#include "../distributions/Distribution.h"
#include "../distributions/BinomialDistribution.h"
#include "../distributions/TwoTieredDistribution.h"
#include "../distributions/SkewedDistribution.h"
#include "../distributions/UniformDistribution.h"

#include "../utils/FileHandler.h"
#include "../utils/MathUtils.h"

class ConferenceConflictDetector {
public:
    /** Constructor for the Conference Conflict Detector
     * 
     * @param N - Number of Sessions
     * @param S - Number of Attendees
     * @param K - Number of Sessions per Attendee
     * @param dist - Distribution used
     * @param size - Size constraint used
     */
    ConferenceConflictDetector(const int N, 
            const int S, 
            const int K, 
            const Dist dist,
            const ConflictSizeConstraint size);
    
    /** Parameterized Constructor 
     * 
     * @param params - Parameters, allows much more control over constants
     */
    ConferenceConflictDetector(
            const ConferenceConflictParams* params);
    
    virtual ~ConferenceConflictDetector();
    
    /** Generates the sessions per each attendee and adds them to the conflict
     *   handler
     */
    void generateConflicts();
    
    /** Writes the results to an output file
     * 
     * @param output - Filename
     */
    void handleResults(std::string output);
private:
    // 
    int sessions;
    int attendees;
    int sesPerAtte;
    
    // Parameterized values
    int lowerBound = 0;
    
    int twoTieredTier = 100;
    float twoTieredSplit = .8;
    
    int showOutput = 0;
    int showOutputNewLine = 20;
    
    int pBatchSize = 1000;
    int eBatchSize = 1000;
    
    
    // Distribution
    Dist distribution;
    Distribution* distributionGenerator;
    
    // Size Constraint 
    ConflictSizeConstraint conflictSize;
    ConflictHandler* conflictHandler;
    
    // Init methods  
    void setUpDistribution();
    void selectConflictSize();
    
    // Adds a set to the conflict handler
    void addConflictSet(std::set<int> set);
};

#endif /* CONFERENCECONFLICTDETECTOR_H */