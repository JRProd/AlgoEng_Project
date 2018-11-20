/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferenceScheduler.cpp
 * Author: jake.rowland
 * 
 * Created on November 18, 2018, 5:45 PM
 */

#include "ConferenceScheduler.h"


ConferenceScheduler::ConferenceScheduler(std::string file) {
    fileHandler.openFile(file, FileFunction::READ);
    
    size = fileHandler.read("N");
}

ConferenceScheduler::~ConferenceScheduler() {
    delete colorer;
}

void ConferenceScheduler::chooseOrder(ColorOrdering order) {
    switch(order) {
        case ColorOrdering::SLO:
            colorer = new Colorer(new SmallestLastOrdering(size));
            break;
        case ColorOrdering::RAN:
            colorer = new Colorer(new RandomOrdering);
            break;
        case ColorOrdering::FIFO:
            colorer = new Colorer(new InOrderOrdering);
            break;
        default:
            colorer = new Colorer(new RandomOrdering);
            break;
    }
}

void ConferenceScheduler::color() {
    populateColorer();
    
    colorer->color();
}

void ConferenceScheduler::displaySchedule(bool stats) {
    std::map<int,std::vector<const Vertex*>> colorMap;
    
    std::vector< Vertex*> vertexList = colorer->getVertexList(true);
    
    for (Vertex* v : vertexList) {
        colorMap[v->getColor()].push_back(v);
    }
    
    std::cout << "Parameters    ------" << std::endl;
    std::cout << "Sessions    : " << fileHandler.read("N") << std::endl;
    std::cout << "Attendees   : " << fileHandler.read("S") << std::endl;
    std::cout << "Sessions Per: " << fileHandler.read("K") << std::endl;
    
    std::cout << "Schedule" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for(auto it = colorMap.begin(); it != colorMap.end(); ++it) {
        std::cout << it->first << " || ";
        for (auto v : it->second) {
            std::cout << v->getSession() << "(" << v->getDegree() << ") ";
        }
        std::cout << std::endl;
    }
    
    if(stats) {
        std::cout << "Stats ------------------" << std::endl;
        int i = 0; 
        int maxDegree = -1;
        std::cout << "Order vs. Degree: [";
        for(Vertex* v: vertexList) {
            int degree = v->getDegree(); 
            std::cout << "(" << i << ", " << degree << "), ";
            if(maxDegree < degree) {
                maxDegree = degree;
            }
            i++;
        }
        std::cout << "]" <<std::endl;
        
        std::cout << "Max Degree      : " << maxDegree << std::endl;
    }
}


void ConferenceScheduler::populateColorer() {
    int pSize = fileHandler.read("N");
    int eSize = fileHandler.read("M");
    
    int* pArray = fileHandler.readList("P");
    int* eArray = fileHandler.readList("E");
    
    int* peArray[] = {pArray, eArray};
    
    colorer->buildVertexList(peArray, pSize, eSize);
}


