/* 
 * File:   UniformDistribution.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 5:20 PM
 */

#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include "Distribution.h"

class UniformDistribution: public Distribution {
public:
    
    /** Uniform Distribution
     * 
     * @param lowerB - Lower bound of the distribution
     * @param upperB - Upper bound of the distribution
     * @param debug - Debug mode
     */
    UniformDistribution(const int lowerB, const int upperB, const int debug);
    virtual ~UniformDistribution();
    
    /** What distribution is this
     * 
     * @return Dist - type of distribution
     */
    Dist whichDistribution() override;
protected:
    
    /** The a uniform session
     * 
     * @return int - Next session chosen
     */
    const int generateSession() override;    
};

#endif /* UNIFORMDISTRIBUTION_H */