/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomOrdering.h
 * Author: jake.rowland
 *
 * Created on November 9, 2018, 5:37 PM
 */

#ifndef RANDOMORDERING_H
#define RANDOMORDERING_H

#include <algorithm>

#include "ColorOrderingInterface.h"
#include "../utils/RandomNumberGenerator.h"

class RandomOrdering : public ColorOrderingInterface{
public:
    RandomOrdering();
    /** @reference {addVertex@ColorOrderingInterface.cpp}
     * 
     */
    virtual void addVertex(Vertex* v) override;
    /** @reference {getOrdering@ColorOrderingInterface.cpp}
     * 
     */
    std::vector<Vertex*> getOrdering() override;

private:
    std::vector<Vertex*> vertexList;
};

#endif /* RANDOMORDERING_H */

