/* 
 * File:   ConflictList.cpp
 * Author: jake.rowland
 * 
 * Created on September 15, 2018, 7:19 PM
 */

#include "ConflictList.h"

ConflictList::ConflictList(int size) {
    if(size < 1) {
        throw std::invalid_argument("ConflictList: Size must be positive");
    }
    N = size;
    conflictCount = 0;
    uniqueConflictCount = 0;
    
    list = nullptr;
}

ConflictList::~ConflictList() {
    delete list;
}

int** ConflictList::peArray() {
    int** peArrays = new int*[2];
    int* pArray = new int[N];
    int* eArray = new int[uniqueConflictCount*2];
    
    // For each session
    int eArrayLoc = 0;
    for(int i = 0; i < N; i++ ) {
        *(pArray+i) = eArrayLoc;
        // For each possible conflict of that session
        ConflictList::Node* root = list;
        while(root != nullptr) {
            // If the first element of the pair is equal to the current element
            //  adding to the pArray
            std::pair<int, int> pair = root->getData();
            if(pair.first == i) {
                *(eArray+eArrayLoc) = pair.second;
                eArrayLoc++;
            }
            root = root->getNext();
        }
        
        if(*(pArray+i) == eArrayLoc) {
            *(pArray+i) = uniqueConflictCount*2;
        }
    }
    
    *(peArrays+0) = pArray;
    *(peArrays+1) = eArray;
    
    return peArrays;
}

void ConflictList::addConflict(std::pair<int, int> pair) {
    if(pair.first == pair.second) {
        return;
    }
    if(!isInList(pair)) {
        // Makes a node with (a,b)
        Node* node = new Node(pair, list);
        // Makes a node with (b,a)
        std::pair <int,int> flipedPair = std::make_pair(
                pair.second, 
                pair.first);
        
        Node* nodeSwap = new Node(flipedPair, node);
        
        list = nodeSwap;
        
        uniqueConflictCount++;
    }
}

ConflictSizeConstrinat ConflictList::whatSize() {
    return ConflictSizeConstrinat::M;
}


bool ConflictList::isInList(std::pair<int, int> pair) {
    // If there is no list currently
    if(list == nullptr) {
        return false;
    }
    
    ConflictList::Node* root = list;
    while(root != nullptr) {
        if(root->getData() == pair) {
            return true;
        }
        root = root->getNext();
    }
    return false;
}

ConflictList::Node::Node(std::pair<int,int> data, Node* next) {
    pair = data;
    nextNode = next;
}

ConflictList::Node::~Node() {
    if(nextNode != nullptr) {
        delete nextNode;
    }
}

std::pair<int,int> ConflictList::Node::getData() {
    return pair;
}

bool ConflictList::Node::hasNext() {
    return nextNode != nullptr;
}

ConflictList::Node* ConflictList::Node::getNext() {
    return nextNode;
}

void ConflictList::Node::setNext(Node* next) {
    nextNode = next;
}




