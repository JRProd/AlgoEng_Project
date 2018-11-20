/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

class ConferenceScheduler {
public:
    ConferenceScheduler(std::string file);
    ~ConferenceScheduler();
    
    void chooseOrder(ColorOrdering order);
    
    void color();
    
    void displaySchedule(bool stats);
private:
    int size = 0;
    
    Colorer* colorer = nullptr;
    FileHandler fileHandler;
    
    void populateColorer();

};

#endif /* CONFERENCESCHEDULER_H */

