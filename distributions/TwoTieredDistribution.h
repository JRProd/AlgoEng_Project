/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TwoTiedDistribution.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 8:26 PM
 */

#ifndef TWOTIEREDDISTRIBUTION_H
#define TWOTIEREDDISTRIBUTION_H

#include "Distribution.h"

class TwoTieredDistribution: public Distribution {
public:
    
    /** Two Tiered Distribution
     * 
     * @param lowerB - Lower bound of the distribution
     * @param tr - Where the tier is split
     * @param splt - The split percentage
     * @param upperB - Upper bound of the distribution
     * @param debug - Debug Mode
     */
    TwoTieredDistribution(
            const int lowerB,
            const int tr,
            const float splt,
            const int upperB,
            const int debug);
    virtual ~TwoTieredDistribution();
    
    /** Generate a unique list of sessions, can flip between two tiered and 
     *   Uniform RNG
     * 
     * @param size - Size of the list
     * @return vector<const int> - List of unique sessions
     */
    virtual std::set<int> generateSessions(const int size) override;
    
    /** What distribution is this
     * 
     * @return Dist - type of distribution
     */
    Dist whichDistribution() override;
private:
    int tier;
    float split;
    
    // If the tier should be used or just uniform RNG
    bool useTieredRng;
    
    /** The a two tiered session
     * 
     * @return int - Next session chosen
     */
    const int generateSession() override;
};

#endif /* TWOTIEREDDISTRIBUTION_H */

