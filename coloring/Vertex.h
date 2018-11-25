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

/** Vertex to control conflicts color and degree
 * 
 * @param sess - Session associated with the vertex
 */
class Vertex {
public:
    Vertex(int sess);
    
    /** Add a conflict to the vertex
     * 
     * @param conflict - Conflict to add
     */
    void addConflict(Vertex* conflict);
    /** Get the conflicts
     * 
     * @return vector<Vertex*> - List of conflicts
     */
    std::vector<Vertex*> getConflicts() const;
    
    /** Get the color of the vertex
     * 
     * @return int - color of the vertex
     */
    int getColor() const;
    /** Sets the color of the vertex
     * 
     * Picks the first non taken color based on conflicts for this vertex.
     */
    void setColor();
    
    /** Get the session associated with the vertex
     * 
     * @return int - Session
     */
    int getSession() const;
    /** Get the degree of the vertex
     * 
     * @return int - Degree of the vertex
     */
    int getDegree() const;
    /** Reduce the degree of the vertex
     * 
     */
    void reduceDegree();
    
    /** Is the vertex removed
     * 
     * @return bool - is removed
     */
    bool isRemoved();
    /** Remove the vertex
     * 
     */
    void remove();
    
private:
    int session;
    int color;
    
    int degree;
    std::vector<Vertex*> conflicts;
    
    bool removed = false;
};

#endif /* VERTEX_H */

