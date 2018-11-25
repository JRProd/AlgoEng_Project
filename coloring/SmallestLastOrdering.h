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

#include <iostream>
#include <vector>

#include "ColorOrderingInterface.h"
#include "Vertex.h"

class SmallestLastOrdering: public ColorOrderingInterface {
public:
    SmallestLastOrdering(int max);
    virtual ~SmallestLastOrdering();
    /** @reference {addVertex@ColorOrderingInterface.cpp}
     * 
     */
    virtual void addVertex(Vertex * v) override;
    /** @reference {getOrdering@ColorOrderingInterface.cpp}
     * 
     */
    virtual std::vector<Vertex*> getOrdering() override;
    /** Displays the degree list
     * 
     */
    void listDegreeLists();
    
private:
    int vertexCount = 0;
    
    int maxDegree;
    
    /** List Node used to aid doubly linked list creation
     * 
     * @param v - Vertex to store at node
     * @param n - Next node in the list
     * @param p - Previous node in the list
     */
    class ListNode {
    public:
        ListNode(Vertex* v, ListNode* n, ListNode* p);
        ~ListNode();
        
        /** Gets the next node
         * 
         * @return ListNode - Next node in the list
         */
        ListNode* getNext();
        /** Sets the next node
         * 
         * @param n - Next list node
         */
        void setNext(ListNode* n);
        
        /** Gets the previous node
         * 
         * @return ListNode - Previous node in the list
         */
        ListNode* getPrev();
        /** Sets the previous node
         * 
         * @param p - Previous node
         */
        void setPrev(ListNode* p);
        
        /** Gets the vertex at the node
         * 
         * @return Vertex* - Vertex at the node
         */
        Vertex* getVertex();
        
        /** Removes the node from the list and reconnects the list 
         *  
         */
        void removeNode();
    private:
        Vertex* vertex;
        ListNode* next;
        ListNode* prev;
    };
    
    ListNode** degreeList;
    
    /** Reduces the degree of a ListNode
     * 
     * @param reduceDegree - ListNode to reduce degree
     */
    void reduceDegreeNode(ListNode* reduceDegree);
    /** Removes a ListNode form the degree list
     * 
     * @param removed - ListNode to remove
     */
    void moveRemovedNode(ListNode* removed);
};

#endif /* DEGREELIST_H */

