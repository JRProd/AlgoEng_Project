/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    UniformDistribution(const int lowerB, const int upperB, const int debug);
    virtual ~UniformDistribution();
    
    Dist whichDistribution() override;
protected:
    const int generateSession() override;    
};

#endif /* UNIFORMDISTRIBUTION_H */

