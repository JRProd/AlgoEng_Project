/* 
 * File:   InOrderOrdering.h
 * Author: jake.rowland
 *
 * Created on November 9, 2018, 5:48 PM
 */

#ifndef INORDERORDERING_H
#define INORDERORDERING_H

#include "ColorOrderingInterface.h"

class InOrderOrdering : public ColorOrderingInterface{
public:
    InOrderOrdering();
    /** @reference {addVertex@ColorOrderingInterface.cpp}
     * 
     */
    virtual void addVertex(Vertex* v) override;
    /** @reference {getOrdering@ColorOrderingInterface.cpp}
     * 
     */
    std::vector<Vertex*> getOrdering() override;
    
private:
    std::vector<Vertex*> vertexList;
};

#endif /* INORDERORDERING_H */

