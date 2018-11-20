/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InOrderOrdering.cpp
 * Author: jake.rowland
 * 
 * Created on November 9, 2018, 5:48 PM
 */

#include "InOrderOrdering.h"

InOrderOrdering::InOrderOrdering() {
}

void InOrderOrdering::addVertex(Vertex* v) {
    vertexList.push_back(v);
}

std::vector<Vertex*> InOrderOrdering::getOrdering() {
    return vertexList;
}


