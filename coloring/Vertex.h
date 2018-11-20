/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex.h
 * Author: jake.rowland
 *
 * Created on November 6, 2018, 9:47 AM
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <set>

class Vertex {
public:
    Vertex(int sess);
    
    void addConflict(Vertex* conflict);
    std::vector<Vertex*> getConflicts() const;
    
    int getColor() const;
    void setColor();
    
    int getSession() const;
    int getDegree() const;
    void reduceDegree();
    
    bool isRemoved();
    void remove();
    
private:
    int session;
    int color;
    
    int degree;
    std::vector<Vertex*> conflicts;
    
    bool removed = false;
};

#endif /* VERTEX_H */

