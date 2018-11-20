/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FileHandlerUnitTest.h
 * Author: jake.rowland
 *
 * Created on Nov 16, 2018, 4:26:32 PM
 */

#ifndef FILEHANDLERUNITTEST_H
#define FILEHANDLERUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../utils/FileHandler.h"

class FileHandlerUnitTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(FileHandlerUnitTest);

    CPPUNIT_TEST(testGetSmallFile);
    CPPUNIT_TEST(testGetLargeFile);

    CPPUNIT_TEST_SUITE_END();

public:
    FileHandlerUnitTest();
    virtual ~FileHandlerUnitTest();
    void setUp();
    void tearDown();

private:
    void testGetSmallFile();
    void testGetLargeFile();
};

#endif /* FILEHANDLERUNITTEST_H */

