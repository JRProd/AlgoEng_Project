/* 
 * File:   ConflictGraph.cpp
 * Author: jake.rowland
 * 
 * Created on September 15, 2018, 6:18 PM
 */

#include "ConflictGraph.h"

ConflictGraph::ConflictGraph(int size) {
    if(size < 1) {
        throw std::invalid_argument("ConflictGraph: Size must be positive");
    }
    N = size;
    conflictCount = 0;
    uniqueConflictCount = 0;
    
    maxConflict = MathUtils::pairs(size);
    
    buildGraph();
}

#include <iostream>
ConflictGraph::ConflictGraph(int** peArray, int pSize, int eSize) {
    std::cout << "Creating graph" << std::endl;
    N = pSize;
    
    conflictCount = -1;
    uniqueConflictCount = 0;
    
    maxConflict = MathUtils::pairs(N);
    
    buildGraph();
    
    for(int p = 0; p < pSize - 1; p++) {
        int sE = *(*(peArray+0)+p);
        int eE = *(*(peArray+0)+p+1);
        
        int nextE = 2;
        while(eE == eSize) {
            if(p+nextE < pSize) {
                eE = *(*(peArray+0)+p+nextE);
                nextE ++;
            } else {
                eE = eSize-1;
                break;
            }
        }
        
        for(int e = sE; e < eE; e++){
            addConflict(std::make_pair(p,*(*(peArray+1)+e)));
        }
        std::cout << std::endl;
    }
    
    int sE = *(*(peArray+0)+pSize-1);
    int eE = eSize;
        
    for(int e = sE; e < eE; e++){
        addConflict(std::make_pair(pSize-1, *(*(peArray+1)+e)));
    }
    std::cout << std::endl;
}


ConflictGraph::~ConflictGraph() {
    for(int i = 0; i < N; i++) {
        if(*(adjacencyGraph+i) != nullptr) {
            delete[] *(adjacencyGraph+i);
        }
    }
    delete[] adjacencyGraph;
}

int** ConflictGraph::peArray() {
    int** peArrays = new int*[2];
    int* pArray = new int[N];
    int* eArray = new int[uniqueConflictCount*2];
    
    // For each session
    int eArrayLoc = 0;
    for(int i = 0; i < N; i++ ) {
        *(pArray+i) = eArrayLoc;
        // For each possible conflict of that session
        bool* sessionConflict = *(adjacencyGraph+i);
        for(int j = 0; j < N; j++) {
            // If that session is a conflict, add to next open location
            //  and increment
            if(*(sessionConflict+j) && j != i) {
                *(eArray+eArrayLoc) = j;
                eArrayLoc++;
            }
        }
        
        if(*(pArray+i) == eArrayLoc){
            *(pArray+i) = uniqueConflictCount*2;
        }
    }
    
    *(peArrays+0) = pArray;
    *(peArrays+1) = eArray;
    
    return peArrays;
}

void ConflictGraph::addConflict(std::pair<int, int> pair) {
    if(pair.first == pair.second) {
        return;
    }
    if( *(*(adjacencyGraph+pair.first)+pair.second) != true) {
        uniqueConflictCount++;
        *(*(adjacencyGraph+pair.first)+pair.second) = true;
        *(*(adjacencyGraph+pair.second)+pair.first) = true;
    }
}

#include <vector>
void ConflictGraph::addToColoring(ColorOrderingInterface* colorOrder) {
    Vertex* vertexArray[N];
    for(int i = 0; i < N; i++) {
        vertexArray[i] = nullptr;
    }
    
    for(int i = 0; i < N; i++) {
        if(vertexArray[i] == nullptr) {
            vertexArray[i] = new Vertex(i);
        }
        
        Vertex* vertex = vertexArray[i];
        for(int j = 0; j < N; j++) {
            if(*(*(adjacencyGraph+i)+j) == true) {
                if(vertexArray[j] == nullptr) {
                    vertexArray[j] = new Vertex(j);
                }
                
                vertex->addConflict(vertexArray[j]);
            }
        }
        
        colorOrder->addVertex(vertex);
    }
}


ConflictSizeConstraint ConflictGraph::whatSize() {
    return ConflictSizeConstraint::N2;
}


void ConflictGraph::buildGraph() {
    adjacencyGraph = new bool*[N];
    
    for(int i = 0; i < N; i++) {
        *(adjacencyGraph+i) = new bool[N];
        for(int j = 0; j < N; j++) {
            *(*(adjacencyGraph+i)+j) = 0;
        }
    }
}