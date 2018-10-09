/* 
 * File:   SkewedDistribution.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 8:28 PM
 */

#ifndef SKEWEDDISTRIBUTION_H
#define SKEWEDDISTRIBUTION_H

#include "Distribution.h"

class SkewedDistribution: public Distribution {
public:
    
    /** Skewed Distribution
     * 
     * @param lowerB - Lower bound of the distribution
     * @param upperB - Upper bound of the distribution
     */
    SkewedDistribution(const int lowerB, const int uppperB);
    virtual ~SkewedDistribution();
    
    /** What distribution is this
     * 
     * @return Dist - type of distribution
     */
    Dist whichDistribution() override;
private:
    
    /** The a binomial session
     * 
     * @return int - Next session chosen
     */
    const int generateSession() override;
};

#endif /* SKEWEDDISTRIBUTION_H */