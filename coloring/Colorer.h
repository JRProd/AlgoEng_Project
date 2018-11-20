/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colorer.h
 * Author: jake.rowland
 *
 * Created on November 12, 2018, 2:45 PM
 */

#ifndef COLORER_H
#define COLORER_H

#include "ColorOrderingInterface.h"
#include "Vertex.h"

class Colorer {
public:
    Colorer(ColorOrderingInterface* colorOrderingInterface);
    virtual ~Colorer();
    
    void buildVertexList(int** peArray, int pSize, int eSize);
    void color();
    
    std::vector<Vertex*> getVertexList(bool ordering);
private:
    ColorOrderingInterface* colorOrdering = nullptr;
    
    int vertexListLength = 0;
    Vertex** vertexList = nullptr;
    
    bool hasColored = false;
    std::vector<Vertex*> ordering;
};

#endif /* COLORER_H */

