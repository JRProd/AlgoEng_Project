/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DegreeList.cpp
 * Author: jake.rowland
 * 
 * Created on November 6, 2018, 9:46 AM
 */

#include "SmallestLastOrdering.h"

#include <iostream>
SmallestLastOrdering::SmallestLastOrdering(int max) {
    maxDegree = max + 1;
    
    degreeList = new ListNode*[maxDegree+1];
    for(int i = 0; i < maxDegree+1; i++) {
        degreeList[i] = nullptr;
    }
}

SmallestLastOrdering::~SmallestLastOrdering() {
    delete degreeList[maxDegree];
    delete[] degreeList;
}

void SmallestLastOrdering::addVertex(Vertex* v) {
    vertexCount += 1;
    int degree = v->getDegree();
    
    ListNode* node = degreeList[degree];
    if(node == nullptr) {
        degreeList[degree] = new ListNode(v, nullptr, nullptr);
    } else {
        ListNode* newNode = new ListNode(v, node, nullptr);
        node->setPrev(newNode);
        degreeList[degree] = newNode;
    }
}

#include <iostream>
std::vector<Vertex*> SmallestLastOrdering::getOrdering() {
    std::vector<Vertex*> smallestLastOrdering;

    for(int i = 0; i < maxDegree; i++) {
        
        if(degreeList[i] != nullptr) {
            // Remove smallest degree node
            ListNode* removed = degreeList[i];
            
            smallestLastOrdering.push_back(removed->getVertex());
            
            moveRemovedNode(removed);

            // Reduce conflicts of that node
            for(Vertex* v: removed->getVertex()->getConflicts()) {
                if(v->isRemoved()) {
                    continue;
                }
                
                int degree = v->getDegree();
                ListNode* node = degreeList[degree];
                
                // Get a matching node
                while(node != nullptr) {
                    if(node->getVertex()->getSession() == v->getSession()) {
                        reduceDegreeNode(node);
                        break;
                    }
                    node = node->getNext();
                }
                
                
                // No node found
                if(node == nullptr) {
                    continue;
                }
                
            }
            
            if (i-2 >= -1) {
                i -= 2;
            } else {
                i -= 1;
            }
        }
    }
    
    std::vector<Vertex*> reveresed;
    for(int i = smallestLastOrdering.size()-1; i >=0; i--) {
        reveresed.push_back(smallestLastOrdering.at(i));
    }
    return reveresed;
}

void SmallestLastOrdering::reduceDegreeNode(ListNode* reduceDegree) {
    // Modify list if its the first
    if(degreeList[reduceDegree->getVertex()->getDegree()] == reduceDegree) {
        degreeList[reduceDegree->getVertex()->getDegree()] = reduceDegree->getNext();
    }
    // Remove node from degree list
    reduceDegree->removeNode();
    
    // Reduce the degree of the node
    reduceDegree->getVertex()->reduceDegree();
    int reducedDegree = reduceDegree->getVertex()->getDegree();
    
    if(degreeList[reducedDegree] != nullptr) {
        // Next in new list is 
        reduceDegree->setNext(degreeList[reducedDegree]);
        
        // Link the node to a new location
        degreeList[reducedDegree]->setPrev(reduceDegree);
        reduceDegree->setNext(degreeList[reducedDegree]);
        
        // Move the location
        degreeList[reducedDegree] = reduceDegree;
    } else {
        degreeList[reducedDegree] = reduceDegree;
    }
}


void SmallestLastOrdering::moveRemovedNode(SmallestLastOrdering::ListNode* removed) {
    removed->getVertex()->remove();
    
    degreeList[removed->getVertex()->getDegree()] = removed->getNext();
    
    removed->removeNode();
    
    // Adds itself to the removed list
    removed->setNext(degreeList[maxDegree]);

    if(degreeList[maxDegree] == nullptr) {
        degreeList[maxDegree] = removed;
    } else {
        degreeList[maxDegree]->setPrev(removed);
        degreeList[maxDegree] = removed;
    }
}


SmallestLastOrdering::ListNode::ListNode(Vertex* v, ListNode* n, ListNode* p) {
    vertex = v;
    next = n;
    prev = p;
}

SmallestLastOrdering::ListNode::~ListNode() {
    if(next != nullptr) {
        delete next;
    }
}

SmallestLastOrdering::ListNode* SmallestLastOrdering::ListNode::getNext() {
    return next;
}

void SmallestLastOrdering::ListNode::setNext(ListNode* n) {
    next = n;
}

SmallestLastOrdering::ListNode* SmallestLastOrdering::ListNode::getPrev() {
    return prev;
}

void SmallestLastOrdering::ListNode::setPrev(ListNode* p) {
    prev = p;
}

Vertex* SmallestLastOrdering::ListNode::getVertex() {
    return vertex;
}

SmallestLastOrdering::ListNode* SmallestLastOrdering::ListNode::removeNode() {
    // Removes the backwards link to this node
    if(next != nullptr) {
        next->setPrev(prev);
    }
    // Removes the forward link to this node
    if(prev != nullptr) {
        prev->setNext(next);
    }
    
    // Destroys the links
    next = nullptr;
    prev = nullptr;
    
    return this;
}

void SmallestLastOrdering::listDegreeLists() {
    for(int i = 0; i <= maxDegree; i++) {
        std::cout << i << ": ";
        
        ListNode* node = degreeList[i];
        while(node != nullptr) {
            std::cout << node->getVertex()->getSession() << " ";
            node = node->getNext();
        }
        
        std::cout << std::endl;
    }
}
