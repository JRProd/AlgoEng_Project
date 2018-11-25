/* 
 * File:   ConferenceScheduler.h
 * Author: jake.rowland
 *
 * Created on November 18, 2018, 5:45 PM
 */

#ifndef CONFERENCESCHEDULER_H
#define CONFERENCESCHEDULER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Colorer.h"
#include "InOrderOrdering.h"
#include "RandomOrdering.h"
#include "SmallestLastOrdering.h"
#include "Vertex.h"
#include "../utils/FileHandler.h"

/** Conference Scheduler
 * 
 * @param file - File to retrieve input from
 */
class ConferenceScheduler {
public:
    ConferenceScheduler(std::string file);
    ~ConferenceScheduler();
    
    /** Select the ordering to use
     * 
     * @param order - ColorOrdering order
     */
    void chooseOrder(ColorOrdering order);
    
    /** Color the graph
     * 
     */
    void color();
    
    /** Display the schedule
     * 
     * @param stats - Display stats
     */
    void displaySchedule(bool stats);
private:
    int size = 0;
    
    Colorer* colorer = nullptr;
    FileHandler fileHandler;
    
    /** Populate colorer with peArray
     * 
     */
    void populateColorer();

};

#endif /* CONFERENCESCHEDULER_H */

