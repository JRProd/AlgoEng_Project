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

#ifndef TWOTIEDDISTRIBUTION_H
#define TWOTIEDDISTRIBUTION_H

#include "Distribution.h"

class TwoTiedDistribution: Distribution {
public:
    TwoTiedDistribution(
            const int lowerB,
            const int tr,
            const float splt,
            const int upperB);
private:
    int tier;
    float split;
    
    const int generateSession() override;
};

#endif /* TWOTIEDDISTRIBUTION_H */

