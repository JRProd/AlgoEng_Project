/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomOrdering.cpp
 * Author: jake.rowland
 * 
 * Created on November 9, 2018, 5:37 PM
 */

#include "RandomOrdering.h"

RandomOrdering::RandomOrdering() {
}

void RandomOrdering::addVertex(Vertex* v) {
    vertexList.push_back(v);
}

std::vector<Vertex*> RandomOrdering::getOrdering() {
    std::vector<Vertex*> ordering = vertexList;
    int size = ordering.size();
    
    RandomNumberGenerator::seedGenerator();
    for(int i = 0; i < size; i++) {
        int rand1 = 
            RandomNumberGenerator::UniformRandomGenerator(0, size);
        int rand2 = 
            RandomNumberGenerator::UniformRandomGenerator(0, size);
        
        std::swap(ordering.at(rand1), ordering.at(rand2));
    }
    
    return ordering;
}


