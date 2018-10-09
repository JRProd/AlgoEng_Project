/* 
 * File:   ConflictSetN2.h
 * Author: jake.rowland
 *
 * Created on September 15, 2018, 6:18 PM
 */

#ifndef CONFLICTGRAPH_H
#define CONFLICTGRAPH_H

#include "ConflictHandler.h"

class ConflictGraph: public ConflictHandler{
public:
    /** Constructor, builds the adjacency graph
     * 
     * @param size - Size of the graph
     */
    ConflictGraph(int size);
    
    /** Destructor, deletes the adjacency graph
     * 
     */
    virtual ~ConflictGraph();
   
    /** @reference {peArray@ConflictHeader.cpp}
     * 
     */
    int** peArray() override;
    
    /** @reference {addConflict@ConflictHeader.cpp}
     * 
     */
    void addConflict(std::pair<int, int> pair) override;
    
    ConflictSizeConstraint whatSize() override;
private:
    int N;
    bool** adjacencyGraph;
    
    /** Builds the adjacency graph
     * 
     */
    void buildGraph();
};

#endif /* CONFLICTGRAPH_H */