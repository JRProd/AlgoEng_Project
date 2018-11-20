/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InOrderOrdering.h
 * Author: jake.rowland
 *
 * Created on November 9, 2018, 5:48 PM
 */

#ifndef INORDERORDERING_H
#define INORDERORDERING_H

#include "ColorOrderingInterface.h"

class InOrderOrdering : public ColorOrderingInterface{
public:
    InOrderOrdering();
    
    virtual void addVertex(Vertex* v) override;
    std::vector<Vertex*> getOrdering() override;
    
private:
    std::vector<Vertex*> vertexList;
};

#endif /* INORDERORDERING_H */

