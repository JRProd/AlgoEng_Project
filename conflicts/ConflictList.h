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
    
    std::set<std::pair<int,int>> pairs;
    
    int N;
    
    /** Checks if the value is in the list
     * 
     * @param pair - Value to look for
     * @return bool - If found
     */
    bool isInSet(std::pair<int, int> pair);
};

#endif /* CONFLICTLIST_H */

