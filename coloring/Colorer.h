/* 
 * File:   Colorer.h
 * Author: jake.rowland
 *
 * Created on November 12, 2018, 2:45 PM
 */

#ifndef COLORER_H
#define COLORER_H

#include "ColorOrderingInterface.h"
#include "Vertex.h"

/** Class to assist in coloring graph 
 * 
 * @param colorOrderingInterface - Color order to use
 */
class Colorer {
public:
    Colorer(ColorOrderingInterface* colorOrderingInterface);
    virtual ~Colorer();
    
    /** Build the vertex list form the peArray
     * 
     * @param peArray - Double integer list with pArray and eArray
     * @param pSize - Size of pArray
     * @param eSize - Size of eArray
     */
    void buildVertexList(int** peArray, int pSize, int eSize);
    
    /** Color the graph
     * 
     */
    void color();
    
    /** Get the ordering of the graph
     * 
     * @param ordering - Use ordering created form the colorOrderingInterface
     * @return vector<Vertex*> - Ordering of the vertices
     */
    std::vector<Vertex*> getVertexList(bool ordering);
private:
    ColorOrderingInterface* colorOrdering = nullptr;
    
    int vertexListLength = 0;
    Vertex** vertexList = nullptr;
    
    bool hasColored = false;
    std::vector<Vertex*> ordering;
};

#endif /* COLORER_H */

