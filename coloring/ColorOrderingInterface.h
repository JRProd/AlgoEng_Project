/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColorOrdering.h
 * Author: jake.rowland
 *
 * Created on November 9, 2018, 5:25 PM
 */

#ifndef COLORORDERINGINTERFACE_H
#define COLORORDERINGINTERFACE_H

#include <vector>

#include "Vertex.h"

enum ColorOrdering {
    SLO,
    RAN,
    FIFO
};

class ColorOrderingInterface {
public:
    virtual void addVertex(Vertex* v) = 0;
    virtual std::vector<Vertex*> getOrdering() = 0;
};

#endif /* COLORORDERING_H */

