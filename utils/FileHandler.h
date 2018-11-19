/* 
 * File:   FileHandler.h
 * Author: jake.rowland
 *
 * Created on September 27, 2018, 10:01 AM
 */

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <map>
#include <string>
#include <sstream>

enum FileFunction {
    READ,
    WRITE
};

class FileHandler {
public:
    /** Build a file handler
     * 
     */
    FileHandler();
    virtual ~FileHandler();
    
    /** Open a file with a filename
     * 
     * @param filename - File to open for output
     */
    void openFile(std::string filename, FileFunction ff);
    
    /** Close the file to clean up
     * 
     */
    void closeFile();
    
    /** Write a key value pair
     * 
     * @param key - String that contains the key
     * @param value - String that contains the value
     * @return bool - Was write successful
     */
    bool write(const std::string key, const std::string value);
    
    std::string readDist();
    
    /** Write a key value pair
     * 
     * @param key - String that contains the key
     * @param value - int that contains the value
     * @return bool - Was write successful
     */
    bool write(const std::string key, const int value);
    
    int read(const std::string key);
    
    /** Write a list of integers
     * 
     * @param key - String that contains the key
     * @param list - List of integers
     * @param size - Size of the list
     * @param batchSize - Group size to write to the file
     * @return bool - Was write successful
     */
    bool writeList(
            const std::string key, 
            const int* const list, 
            const int size, 
            const int batchSize);
    
    int* readList(const std::string key);
    
private:
    std::fstream file;
    
    std::map<std::string, int> intMap;
    std::map<std::string, int*> listMap;
    
    std::string dist;
    
    /** Can the ofstream write
     * 
     * @return bool - If the file can write
     */
    bool canWrite();
    
    void openForRead(std::string filename);
    
    void openForWrite(std::string filename);
};

#endif /* FILEHANDLER_H */