/* 
 * File:   RandomNumberGenerator.h
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 1:15 PM
 */

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <stdlib.h>
#include <time.h>

#include <stdexcept>

class RandomNumberGenerator {
public:
    /** Generate a random number with a uniform distribution
     * 
     * @param lowerBound - Inclusive lower bound for the random number
     * @param upperBound - exclusive upper bound for the random number
     * @return int - Random number generated
     */
    static int UniformRandomGenerator(
            const int lowerBound, 
            const int upperBound);
    
    /** Generate a random number with a skewed distribution
     * 
     * @param lowerBound - Inclusive lower bound for the random number
     * @param upperBound - exclusive upper bound for the random number
     * @return int - Random number generated
     */
    static int SkewedRandomGenerator(
            const int lowerBound, 
            const int upperbound);
    
    /** Generate a random number with a two tiered distribution
     * 
     * @param lowerBound - Inclusive lower bound for the random number
     * @param teir - What point (lowerBound, upperBound) where the tiers split
     * @param split - Percentage of the split [0,1]
     * @param upperBound - Exclusive upper bound for the random number
     * @return int - Random number generated
     */
    static int TwoTieredRandomGenerator(
            const int lowerBound, 
            const int teir, 
            const float split, 
            const int upperBound);
    
    /** Generate a random number with a binomial distribution
     * 
     * @param lowerBound - Inclusive lower bound for the random number
     * @param upperBound - exclusive upper bound for the random number
     * @return int - Random number generated
     */
    static int BinomialRandomGenerator(
            const int lowerBound, 
            const int upperBound);
    
    static void seedGenerator();
    static void seedGenerator(const time_t seed);
    
private:
    /** Generate a random number
     * 
     * @param lowerBound - Inclusive lower bound for the random number
     * @param upperBound - exclusive upper bound for the random number
     * @return int - Random number generated
     */
    static int randomNumber(const int lowerBound, const int upperBound);
};

#endif /* RANDOMNUMBERGENERATOR_H */