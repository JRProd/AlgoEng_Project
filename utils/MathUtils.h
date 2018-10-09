/* 
 * File:   MathUtils.h
 * Author: jake.rowland
 *
 * Created on September 17, 2018, 11:47 AM
 */

#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <stdexcept>

class MathUtils {
public:
    /** Factorial function
     * 
     * @param n - Number to calculate factorial
     * @return unsigned long - Result of the factorial
     */
    static unsigned long factorial(const int n);
    
    /** n C k function. n!/(k!(n-k)!)
     * 
     * @param n - Number of options
     * @param k - Number of chosen values
     * @return unsigned long - Combinations possible
     */
    static unsigned long choose(const int n, const int k);
    
    /** Specific n C k function where k=2
     * 
     * @param n - Number of options
     * @return unsigned long - Number of pairs possible
     */
    static unsigned long pairs(const int n);
    
private:
    /** Calculate n!/(n-s)! more efficiently
     * 
     * @param n - Number to calculate factorial
     * @param s - Number to stop at
     * @return unsigned long - Result of the partial factorial
     */
    static unsigned long partialFactorial(const int n, const int s);
};

#endif /* MATHUTILS_H */