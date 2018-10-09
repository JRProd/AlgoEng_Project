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

void FileHandler::openFile(std::string filename) {
    if(file.is_open()) {
        closeFile();
    }
    
    file.open(filename);
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

bool FileHandler::write(const std::string key, const int value) {
    if(!canWrite()) {
        return false;
    }
    
    file << key << std::endl << value << std::endl;
    return true;
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

bool FileHandler::canWrite() {
    return file.is_open();
}