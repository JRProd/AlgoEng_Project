/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FileHandlerUnitTest.cpp
 * Author: jake.rowland
 *
 * Created on Nov 16, 2018, 4:26:32 PM
 */

#include "FileHandlerUnitTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FileHandlerUnitTest);

FileHandlerUnitTest::FileHandlerUnitTest() {
}

FileHandlerUnitTest::~FileHandlerUnitTest() {
}

void FileHandlerUnitTest::setUp() {
}

void FileHandlerUnitTest::tearDown() {
}

void FileHandlerUnitTest::testGetSmallFile() {
    FileHandler fileHandler;
    fileHandler.openFile("test.txt", FileFunction::READ);
    
    CPPUNIT_ASSERT(true);
}

void FileHandlerUnitTest::testGetLargeFile() {
    CPPUNIT_ASSERT(false);
}

