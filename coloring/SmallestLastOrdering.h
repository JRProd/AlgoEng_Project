/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DegreeList.h
 * Author: jake.rowland
 *
 * Created on November 6, 2018, 9:46 AM
 */

#ifndef SMALLESTLASTORDERING_H
#define SMALLESTLASTORDERING_H

#include <vector>

#include "ColorOrderingInterface.h"
#include "Vertex.h"

class SmallestLastOrdering: public ColorOrderingInterface {
public:
    SmallestLastOrdering(int max);
    virtual ~SmallestLastOrdering();
    
    virtual void addVertex(Vertex * v) override;
    virtual std::vector<Vertex*> getOrdering() override;
    
    void listDegreeLists();
    
private:
    int vertexCount = 0;
    
    int maxDegree;
    
    class ListNode {
    public:
        ListNode(Vertex* v, ListNode* n, ListNode* p);
        ~ListNode();
        
        ListNode* getNext();
        void setNext(ListNode* n);
        
        ListNode* getPrev();
        void setPrev(ListNode* p);
        
        Vertex* getVertex();
        
        ListNode* removeNode();
    private:
        Vertex* vertex;
        ListNode* next;
        ListNode* prev;
    };
    
    ListNode** degreeList;
    void reduceDegreeNode(ListNode* reduceDegree);
    void moveRemovedNode(ListNode* removed);
};

#endif /* DEGREELIST_H */

