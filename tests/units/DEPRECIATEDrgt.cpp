/* 
 * File:   DistributionTest.cpp
 * Author: jake.rowland
 *
 * Created on September 10, 2018, 1:22 PM
 */

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "../../utils/RandomNumberGenerator.h"


const int countHisto(const int* const histo, const int buckets) {
    int total = 0;
    for(int i = 0; i < buckets; i++) {
        total += *(histo+i);
    }
    
    return total;
}

/*
 *
 * @param list - List of integers [1,10]
 * @param size - Size of the above list
 * 
 * @return int* - Histogram with the value at a index = to the times that index 
 *  was in the list. Will always be of size UPPER_BOUND
 */
const int* histogram(const int* const list, const int size, const int buckets) {
    int* histo = new int[buckets+1];
    std::fill_n(histo, buckets, 0);
    for(int i = 0; i < size; i++) {
        // Offset histo pointer by the current value in the list -1
        int value = *(list+i);
        *(histo+value) = *(histo+value) + 1;
    }
    
    *(histo+buckets) = countHisto(histo, buckets);
    
    return histo;
}

void printList(const int* const list, const int size) {
    std::cout << "[";
    for(int i = 0; i < size; i++) {
        if (i != size-1) {
            std::cout << *(list+i) << ",";
        }
        else {
            std::cout << *(list+i);
        }
    }
    std::cout << "]" << std::endl;
}

/*
 * Simple C++ Test Suite
 */

void uniformDistributionTest(int size, int upperBound) {
    std::cout << "Uniform distribution test" << std::endl;
    RandomNumberGenerator::seedGenerator(time(nullptr));
   
    int* distro = new int[size];
    
    for(int i = 0; i < size; i++) {
        *(distro+i) = RandomNumberGenerator::UniformRandomGenerator(0, upperBound);
    }
    
    const int* histo = histogram(distro,size,upperBound);

    if (*(histo+upperBound) != size) {
        std::cout << "%TEST_FAILED%" << size - *(histo+upperBound) 
                << " entries missing from the histogram";
    } else {
        std::cout << "Histogram has " << *(histo+upperBound) << " entries" 
                << std::endl;
    }
    
    delete[] distro;
    delete[] histo;
}

void skewedDistributionTest(int size, int upperBound) {
    std::cout << "Skewed distribution test" << std::endl;
    RandomNumberGenerator::seedGenerator(time(nullptr));
   
    int* distro = new int[size];
    
    for(int i = 0; i < size; i++) {
        *(distro+i) = RandomNumberGenerator::SkewedRandomGenerator(0, upperBound);
    }
    
    const int* histo = histogram(distro,size,upperBound);

    if (*(histo+upperBound) != size) {
        std::cout << "%TEST_FAILED%" << size - *(histo+upperBound) 
                << " entries missing from the histogram";
    } else {
        std::cout << "Histogram has " << *(histo+upperBound) << " entries" 
                << std::endl;
    }
    
    delete[] distro;
    delete[] histo;
}

void twoTieredDistributionTest(int size, int tier, float split, int upperBound) {
    std::cout << "Two tiered distribution test" << std::endl;
    RandomNumberGenerator::seedGenerator(time(nullptr));
   
    int* distro = new int[size];
    
    for(int i = 0; i < size; i++) {
        *(distro+i) = RandomNumberGenerator::TwoTieredRandomGenerator(
                0,
                tier,
                split,
                upperBound);
    }
    
    const int* histo = histogram(distro,size,upperBound);

    if (*(histo+upperBound) != size) {
        std::cout << "%TEST_FAILED%" << size - *(histo+upperBound) 
                << " entries missing from the histogram" << std::endl;
    } else {
        std::cout << "Histogram has " << *(histo+upperBound) << " entries" 
                << std::endl;
    }
    
    delete[] distro;
    delete[] histo;
}

void binomialDistributionTest(int size, int upperBound) {
    std::cout << "Binomial distribution test" << std::endl;
    
    RandomNumberGenerator::seedGenerator(time(nullptr));
   
    int* distro = new int[size];
    
    for(int i = 0; i < size; i++) {
        *(distro+i) = RandomNumberGenerator::BinomialRandomGenerator(0, upperBound);
    }
    
    const int* histo = histogram(distro,size,upperBound);

    if (*(histo+upperBound) != size) {
        std::cout << "%TEST_FAILED% time=0 testname=binomialDistributionTest (DistributionTest) message=entries missing from the histogram" << std::endl;
    } else {
        std::cout << "Histogram has " << *(histo+upperBound) << " entries" 
                  << std::endl;
    }
    
    delete[] distro;
    delete[] histo;
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% DistributionTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (DistributionTest)" << std::endl;
    uniformDistributionTest(1000000, 100);
    std::cout << "%TEST_FINISHED% time=0 test1 (DistributionTest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (DistributionTest)\n" << std::endl;
    skewedDistributionTest(1000000,100);
    std::cout << "%TEST_FINISHED% time=0 test2 (DistributionTest)" << std::endl;
    
    std::cout << "%TEST_STARTED% test3 (DistributionTest)\n" << std::endl;
    twoTieredDistributionTest(1000000, 20, .8, 100);
    std::cout << "%TEST_FINISHED% time=0 test2 (DistributionTest)" << std::endl;
    
    std::cout << "%TEST_STARTED% test4 (DistributionTest)\n" << std::endl;
    binomialDistributionTest(1000000,100);
    std::cout << "%TEST_FINISHED% time=0 test2 (DistributionTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

