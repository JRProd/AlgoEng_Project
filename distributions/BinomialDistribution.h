/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    BinomialDistribution(const int lowerB, const int upperB);
    virtual ~BinomialDistribution();
    
    Dist whichDistribution() override;
private:
    const int generateSession() override;
};

#endif /* BINOMIALDISTRIBUTION_H */

