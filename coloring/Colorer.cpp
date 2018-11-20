/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colorer.cpp
 * Author: jake.rowland
 * 
 * Created on November 12, 2018, 2:45 PM
 */

#include "Colorer.h"

Colorer::Colorer(ColorOrderingInterface* colorOrderingInterface) {
    colorOrdering = colorOrderingInterface;
}

Colorer::~Colorer() {
    delete[] vertexList;
}

void Colorer::buildVertexList(int** peArray, int pSize, int eSize) {
    if(vertexList != nullptr) {
        //TODO: Throw error because vertexList already built.
    }
    
    vertexListLength = pSize;
    vertexList = new Vertex*[vertexListLength];
    for(int p = 0; p < pSize - 1; p++) {
        if(vertexList[p] == nullptr) {
            vertexList[p] = new Vertex(p);
        }
        
        int sE = *(*(peArray+0)+p);
        int eE = *(*(peArray+0)+p+1);
        int nextE = 2;
        while(eE == eSize) {
            if(p+nextE < pSize) {
                eE = *(*(peArray+0)+p+nextE);
                nextE ++;
            } else {
                eE = eSize;
                break;
            }
        }
        
        for(int e = sE; e < eE; e++){
            int conflictSession = *(*(peArray+1)+e);
            if(vertexList[conflictSession] == nullptr) {
                vertexList[conflictSession] = new Vertex(conflictSession);
            }
            
            vertexList[p]->addConflict(vertexList[conflictSession]);
        }
    }
    
    if(vertexList[pSize-1] == nullptr) {
        vertexList[pSize-1] = new Vertex(pSize-1);
    }
    
    int sE = *(*(peArray+0)+pSize-1);
    int eE = eSize;
    for(int e = sE; e < eE; e++){
        int conflictSession = *(*(peArray+1)+e);
        if(vertexList[conflictSession] == nullptr) {
            vertexList[conflictSession] = new Vertex(conflictSession);
        }
            
        vertexList[pSize-1]->addConflict(vertexList[conflictSession]);
    }
}

void Colorer::color() {
    for(int i = 0; i < vertexListLength; i++) {
        colorOrdering->addVertex(*(vertexList+i));
    }
    
    ordering = colorOrdering->getOrdering();
    hasColored = true;
    
    for(Vertex* v : ordering) {
        v->setColor();
    }
}

std::vector<Vertex*> Colorer::getVertexList(bool ordered) {
    if(ordered && hasColored) {
        return ordering;
    }
    std::vector<Vertex*> list;
    for(int i = 0; i < vertexListLength; i++) {
        list.push_back(*(vertexList+i));
    }
    return list;
}



