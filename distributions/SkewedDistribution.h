/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    SkewedDistribution(const int lowerB, const int uppperB, const int debug);
    virtual ~SkewedDistribution();
    
    Dist whichDistribution() override;
private:
    const int generateSession() override;
};

#endif /* SKEWEDDISTRIBUTION_H */

