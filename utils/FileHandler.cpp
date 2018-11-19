/* 
 * File:   FileHandler.cpp
 * Author: jake.rowland
 * 
 * Created on September 27, 2018, 10:01 AM
 */

#include "FileHandler.h"

FileHandler::FileHandler() {
}

FileHandler::~FileHandler() {
    file.close();
}

void FileHandler::openFile(std::string filename, FileFunction ff) {
    switch(ff) {
        case FileFunction::READ:
            openForRead(filename);
            break;
        case FileFunction::WRITE:
            openForWrite(filename);
            break;
        default:
            openForWrite(filename);
            break;
    }
}

void FileHandler::closeFile() {
    file.close();
}

bool FileHandler::write(const std::string key, const std::string value) {
    if(!canWrite()) {
        return false;
    }
    
    file << key << std::endl << value << std::endl;
    return true;
}

std::string FileHandler::readDist() {
    return dist;
}


bool FileHandler::write(const std::string key, const int value) {
    if(!canWrite()) {
        return false;
    }
    
    file << key << std::endl << value << std::endl;
    return true;
}

int FileHandler::read(const std::string key) {
    return intMap[key];
}


bool FileHandler::writeList(
        const std::string key, 
        const int* const list, 
        const int size, 
        const int batchSize) {
    if(!canWrite()) {
        return false;
    }
    if(batchSize < 1) {
        throw std::invalid_argument(
                "FileHandler::writeList: Batch size must be > zero");
    }
    
    file << key << std::endl;
    for(int i = 0; i < size; i+=batchSize) {
        
        //Build string to insert
        std::stringstream sStream;
        for(int j = 0; i+j < size && j < batchSize; j++) {
            sStream << *(list+i+j) << "\n";
        }
        file << sStream.str();
    }
    return true;
}

int* FileHandler::readList(const std::string key) {
    return listMap[key];
}


bool FileHandler::canWrite() {
    return file.is_open();
}

#include <iostream>
void FileHandler::openForRead(std::string filename) {
    if(!file.is_open()) {
        file.open(filename, std::ios::in);
    }
    
    std::string line;
    while(std::getline(file, line)) {
        if(line == "P" || line == "E") {
            std::string key = line;
            int size = 0;
            
            if(line == "P") {
                size = intMap.at("N");
            } else {
                size = intMap.at("M");
            }
            
            int* list = new int[size];
            for(int i = 0; i < size; i++) {
                std::getline(file, line);
                int value = std::stoi(line);
                list[i] = value;
            }
            
            std::cout << "Adding " << key << "->" << list << " to list map" << std::endl;
            
            listMap[key] = list;
        } else if (line == "DIST") {
            std::getline(file,dist);
        }
        else {
            std::string key = line;
            std::getline(file,line);
            
            std::cout << "Adding " << key << "->" << line << " to map" << std::endl;
            
            int intVal = std::stoi(line);

            intMap[key] = intVal;
        }
    }
    
    file.close();
}

void FileHandler::openForWrite(std::string filename) {
    if(!file.is_open()) {
         file.open(filename, std::ios::out);
    }
}
