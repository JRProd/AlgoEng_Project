/* 
 * File:   ConflictList.h
 * Author: jake.rowland
 *
 * Created on September 15, 2018, 7:19 PM
 */

#ifndef CONFLICTLIST_H
#define CONFLICTLIST_H

#include <set>

#include "ConflictHandler.h"

class ConflictList: public ConflictHandler{
public:
    /** Constructor
     * 
     * @param size - Number of sessions possible
     */
    ConflictList(int size);
    
    /** Destructor, deletes list
     * 
     */
    virtual ~ConflictList();
    
    /** @reference {peArray@ConflictHeader.cpp}
     * 
     */
    int** peArray() override;
    
    /** @reference {addConflict@ConflictHeader.cpp}
     * 
     */
    void addConflict(std::pair<int,int> pair) override;
    
    ConflictSizeConstrinat whatSize() override;
private: 
    const bool USE_HASH_SET = false;
    std::set<std::pair<int,int>> pairsAdded;
    
    int N;
    
    /** Checks if the value is in the list
     * 
     * @param pair - Value to look for
     * @return bool - If found
     */
    bool isInList(std::pair<int,int> pair);
    
    /** Node class to help linked list implementation
     * 
     * @param data - Data to store in the node
     * @param next - Next node in the list
     */
    class Node {
    public:
        /** Constructor
         * 
         * @param data - Data in the node
         * @param next - Next node in the list
         */
        Node(std::pair<int,int> data, Node* next);
        
        /** Destructor, deletes next node first then current one
         * 
         */
        ~Node();
        
        /** Get the data in the node
         * 
         * @return std::pair<int,int> - Data stored
         */
        std::pair<int,int> getData();
        
        /** Check if there is another node
         * 
         * @return bool - If another node exists
         */
        bool hasNext();
        
        /** Get the next node
         * 
         * @return Node* - Pointer to next node
         */
        Node* getNext();
        
        /** Set the next node value
         * 
         * @param next - Next node
         */
        void setNext(Node* next);
    private:
        std::pair<int,int> pair;
        Node* nextNode;
    };
    
    Node* list;
};

#endif /* CONFLICTLIST_H */

