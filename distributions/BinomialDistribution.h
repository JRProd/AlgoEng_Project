/* 
 * File:   BinomialDistribution.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 8:38 PM
 */

#ifndef BINOMIALDISTRIBUTION_H
#define BINOMIALDISTRIBUTION_H

#include "Distribution.h"

class BinomialDistribution: public Distribution {
public:
    
    /** Binomial Distribution
     * 
     * @param lowerB - Lower bound of the distribution
     * @param upperB - Upper bound of the distribution
     */
    BinomialDistribution(const int lowerB, const int upperB);
    virtual ~BinomialDistribution();
    
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

#endif /* BINOMIALDISTRIBUTION_H */