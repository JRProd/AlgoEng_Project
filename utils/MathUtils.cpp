/* 
 * File:   MathUtils.cpp
 * Author: jake.rowland
 * 
 * Created on September 17, 2018, 11:47 AM
 */

#include "MathUtils.h"

unsigned long MathUtils::factorial(const int n) {
    if(n < 0) {
        throw std::invalid_argument("MathUtils::factorial: N must be non-negative");
    }
    return partialFactorial(n, 1);
}

unsigned long MathUtils::choose(const int n, const int k) {
    if (n < k) {
        throw std::invalid_argument("MathUtils::choose: N must be at least as large as K");
    }
    unsigned long top = partialFactorial(n,n-k);
    unsigned long bottom = factorial(k);
    
    return top/bottom;
}

unsigned long MathUtils::pairs(const int n) {
    if (n < 2) {
        throw std::invalid_argument("MathUtils::pairs: N must be at least as large as 2");
    }
    return choose(n, 2);
}

unsigned long MathUtils::partialFactorial(const int n, const int s) {
    // Basic recursive factorial with an additional stop case
    if (n == 0 || n == 1) {
        return 1;
    } else if (n == s) {
        return 1;
    }
    return n * partialFactorial(n-1, s);
}