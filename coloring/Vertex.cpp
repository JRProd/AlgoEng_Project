/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex.cpp
 * Author: jake.rowland
 * 
 * Created on November 6, 2018, 9:47 AM
 */

#include "Vertex.h"

Vertex::Vertex(int sess) {
    session = sess;
    degree = 0;
    
    color = -1;
    
    removed = false;
}

void Vertex::addConflict(Vertex* conflict) {
    conflicts.push_back(conflict);
    degree += 1;
}

std::vector<Vertex*> Vertex::getConflicts() const{
    return conflicts;
}


int Vertex::getColor() const {
    return color;
}

void Vertex::setColor() {
    int c = 0;
    std::set<int> unavailable;
    for (Vertex* v: conflicts) {
        unavailable.insert(v->color);
        while (unavailable.find(c) != unavailable.end()) {
            c+=1;
        }
    }
    
    color = c;
}

int Vertex::getSession() const {
    return session;
}

int Vertex::getDegree() const {
    return degree;
}

void Vertex::reduceDegree() {
    degree -= 1;
}

bool Vertex::isRemoved() {
    return removed;
}

void Vertex::remove() {
    removed = true;
}




