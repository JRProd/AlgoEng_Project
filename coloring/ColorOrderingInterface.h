/* 
 * File:   ColorOrdering.h
 * Author: jake.rowland
 *
 * Created on November 9, 2018, 5:25 PM
 */

#ifndef COLORORDERINGINTERFACE_H
#define COLORORDERINGINTERFACE_H

#include <vector>

#include "Vertex.h"

/** Enum to quickly choose what kind of ordering to use
 *
 */
enum ColorOrdering {
    SLO,
    RAN,
    FIFO
};

class ColorOrderingInterface {
public:
    /** Add a vertex to a ordering
     *
     * @param v - Vertex to add to ordering
     */
    virtual void addVertex(Vertex* v) = 0;
    /** Get the ordering based on type
     * 
     * @return vector<Vertex*> - the ordering
     */
    virtual std::vector<Vertex*> getOrdering() = 0;
};

#endif /* COLORORDERING_H */

