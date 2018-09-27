#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/conference/ConferenceConflictDetector.o \
	${OBJECTDIR}/conflicts/ConflictGraph.o \
	${OBJECTDIR}/conflicts/ConflictHandler.o \
	${OBJECTDIR}/conflicts/ConflictList.o \
	${OBJECTDIR}/distributions/BinomialDistribution.o \
	${OBJECTDIR}/distributions/Distribution.o \
	${OBJECTDIR}/distributions/SkewedDistribution.o \
	${OBJECTDIR}/distributions/TwoTieredDistribution.o \
	${OBJECTDIR}/distributions/UniformDistribution.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/utils/FileHandler.o \
	${OBJECTDIR}/utils/MathUtils.o \
	${OBJECTDIR}/utils/RandomNumberGenerator.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/units/ConflictGraphTestRunner.o \
	${TESTDIR}/tests/units/ConflictGraphUnitTest.o \
	${TESTDIR}/tests/units/ConflictListTestRunner.o \
	${TESTDIR}/tests/units/ConflictListUnitTest.o \
	${TESTDIR}/tests/units/DistributionTestRunner.o \
	${TESTDIR}/tests/units/DistributionUnitTest.o \
	${TESTDIR}/tests/units/MathUtilTestRunner.o \
	${TESTDIR}/tests/units/MathUtilUnitTest.o \
	${TESTDIR}/tests/units/RandomGeneratorTestRunner.o \
	${TESTDIR}/tests/units/RandomGeneratorUnitTest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algoeng_project

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algoeng_project: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algoeng_project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/conference/ConferenceConflictDetector.o: conference/ConferenceConflictDetector.cpp
	${MKDIR} -p ${OBJECTDIR}/conference
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conference/ConferenceConflictDetector.o conference/ConferenceConflictDetector.cpp

${OBJECTDIR}/conflicts/ConflictGraph.o: conflicts/ConflictGraph.cpp
	${MKDIR} -p ${OBJECTDIR}/conflicts
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictGraph.o conflicts/ConflictGraph.cpp

${OBJECTDIR}/conflicts/ConflictHandler.o: conflicts/ConflictHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/conflicts
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictHandler.o conflicts/ConflictHandler.cpp

${OBJECTDIR}/conflicts/ConflictList.o: conflicts/ConflictList.cpp
	${MKDIR} -p ${OBJECTDIR}/conflicts
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictList.o conflicts/ConflictList.cpp

${OBJECTDIR}/distributions/BinomialDistribution.o: distributions/BinomialDistribution.cpp
	${MKDIR} -p ${OBJECTDIR}/distributions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/BinomialDistribution.o distributions/BinomialDistribution.cpp

${OBJECTDIR}/distributions/Distribution.o: distributions/Distribution.cpp
	${MKDIR} -p ${OBJECTDIR}/distributions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/Distribution.o distributions/Distribution.cpp

${OBJECTDIR}/distributions/SkewedDistribution.o: distributions/SkewedDistribution.cpp
	${MKDIR} -p ${OBJECTDIR}/distributions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/SkewedDistribution.o distributions/SkewedDistribution.cpp

${OBJECTDIR}/distributions/TwoTieredDistribution.o: distributions/TwoTieredDistribution.cpp
	${MKDIR} -p ${OBJECTDIR}/distributions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/TwoTieredDistribution.o distributions/TwoTieredDistribution.cpp

${OBJECTDIR}/distributions/UniformDistribution.o: distributions/UniformDistribution.cpp
	${MKDIR} -p ${OBJECTDIR}/distributions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/UniformDistribution.o distributions/UniformDistribution.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/utils/FileHandler.o: utils/FileHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/FileHandler.o utils/FileHandler.cpp

${OBJECTDIR}/utils/MathUtils.o: utils/MathUtils.cpp
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/MathUtils.o utils/MathUtils.cpp

${OBJECTDIR}/utils/RandomNumberGenerator.o: utils/RandomNumberGenerator.cpp
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/RandomNumberGenerator.o utils/RandomNumberGenerator.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/units/ConflictGraphTestRunner.o ${TESTDIR}/tests/units/ConflictGraphUnitTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lcppunit 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/units/ConflictListTestRunner.o ${TESTDIR}/tests/units/ConflictListUnitTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   -lcppunit 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/units/DistributionTestRunner.o ${TESTDIR}/tests/units/DistributionUnitTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lcppunit 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/units/MathUtilTestRunner.o ${TESTDIR}/tests/units/MathUtilUnitTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lcppunit 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/units/RandomGeneratorTestRunner.o ${TESTDIR}/tests/units/RandomGeneratorUnitTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lcppunit 


${TESTDIR}/tests/units/ConflictGraphTestRunner.o: tests/units/ConflictGraphTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/ConflictGraphTestRunner.o tests/units/ConflictGraphTestRunner.cpp


${TESTDIR}/tests/units/ConflictGraphUnitTest.o: tests/units/ConflictGraphUnitTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/ConflictGraphUnitTest.o tests/units/ConflictGraphUnitTest.cpp


${TESTDIR}/tests/units/ConflictListTestRunner.o: tests/units/ConflictListTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/ConflictListTestRunner.o tests/units/ConflictListTestRunner.cpp


${TESTDIR}/tests/units/ConflictListUnitTest.o: tests/units/ConflictListUnitTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/ConflictListUnitTest.o tests/units/ConflictListUnitTest.cpp


${TESTDIR}/tests/units/DistributionTestRunner.o: tests/units/DistributionTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/DistributionTestRunner.o tests/units/DistributionTestRunner.cpp


${TESTDIR}/tests/units/DistributionUnitTest.o: tests/units/DistributionUnitTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/DistributionUnitTest.o tests/units/DistributionUnitTest.cpp


${TESTDIR}/tests/units/MathUtilTestRunner.o: tests/units/MathUtilTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/MathUtilTestRunner.o tests/units/MathUtilTestRunner.cpp


${TESTDIR}/tests/units/MathUtilUnitTest.o: tests/units/MathUtilUnitTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/MathUtilUnitTest.o tests/units/MathUtilUnitTest.cpp


${TESTDIR}/tests/units/RandomGeneratorTestRunner.o: tests/units/RandomGeneratorTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/RandomGeneratorTestRunner.o tests/units/RandomGeneratorTestRunner.cpp


${TESTDIR}/tests/units/RandomGeneratorUnitTest.o: tests/units/RandomGeneratorUnitTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests/units
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/units/RandomGeneratorUnitTest.o tests/units/RandomGeneratorUnitTest.cpp


${OBJECTDIR}/conference/ConferenceConflictDetector_nomain.o: ${OBJECTDIR}/conference/ConferenceConflictDetector.o conference/ConferenceConflictDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/conference
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conference/ConferenceConflictDetector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conference/ConferenceConflictDetector_nomain.o conference/ConferenceConflictDetector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conference/ConferenceConflictDetector.o ${OBJECTDIR}/conference/ConferenceConflictDetector_nomain.o;\
	fi

${OBJECTDIR}/conflicts/ConflictGraph_nomain.o: ${OBJECTDIR}/conflicts/ConflictGraph.o conflicts/ConflictGraph.cpp 
	${MKDIR} -p ${OBJECTDIR}/conflicts
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conflicts/ConflictGraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictGraph_nomain.o conflicts/ConflictGraph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conflicts/ConflictGraph.o ${OBJECTDIR}/conflicts/ConflictGraph_nomain.o;\
	fi

${OBJECTDIR}/conflicts/ConflictHandler_nomain.o: ${OBJECTDIR}/conflicts/ConflictHandler.o conflicts/ConflictHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/conflicts
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conflicts/ConflictHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictHandler_nomain.o conflicts/ConflictHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conflicts/ConflictHandler.o ${OBJECTDIR}/conflicts/ConflictHandler_nomain.o;\
	fi

${OBJECTDIR}/conflicts/ConflictList_nomain.o: ${OBJECTDIR}/conflicts/ConflictList.o conflicts/ConflictList.cpp 
	${MKDIR} -p ${OBJECTDIR}/conflicts
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conflicts/ConflictList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conflicts/ConflictList_nomain.o conflicts/ConflictList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conflicts/ConflictList.o ${OBJECTDIR}/conflicts/ConflictList_nomain.o;\
	fi

${OBJECTDIR}/distributions/BinomialDistribution_nomain.o: ${OBJECTDIR}/distributions/BinomialDistribution.o distributions/BinomialDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/distributions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/distributions/BinomialDistribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/BinomialDistribution_nomain.o distributions/BinomialDistribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/distributions/BinomialDistribution.o ${OBJECTDIR}/distributions/BinomialDistribution_nomain.o;\
	fi

${OBJECTDIR}/distributions/Distribution_nomain.o: ${OBJECTDIR}/distributions/Distribution.o distributions/Distribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/distributions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/distributions/Distribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/Distribution_nomain.o distributions/Distribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/distributions/Distribution.o ${OBJECTDIR}/distributions/Distribution_nomain.o;\
	fi

${OBJECTDIR}/distributions/SkewedDistribution_nomain.o: ${OBJECTDIR}/distributions/SkewedDistribution.o distributions/SkewedDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/distributions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/distributions/SkewedDistribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/SkewedDistribution_nomain.o distributions/SkewedDistribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/distributions/SkewedDistribution.o ${OBJECTDIR}/distributions/SkewedDistribution_nomain.o;\
	fi

${OBJECTDIR}/distributions/TwoTieredDistribution_nomain.o: ${OBJECTDIR}/distributions/TwoTieredDistribution.o distributions/TwoTieredDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/distributions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/distributions/TwoTieredDistribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/TwoTieredDistribution_nomain.o distributions/TwoTieredDistribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/distributions/TwoTieredDistribution.o ${OBJECTDIR}/distributions/TwoTieredDistribution_nomain.o;\
	fi

${OBJECTDIR}/distributions/UniformDistribution_nomain.o: ${OBJECTDIR}/distributions/UniformDistribution.o distributions/UniformDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/distributions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/distributions/UniformDistribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distributions/UniformDistribution_nomain.o distributions/UniformDistribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/distributions/UniformDistribution.o ${OBJECTDIR}/distributions/UniformDistribution_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/utils/FileHandler_nomain.o: ${OBJECTDIR}/utils/FileHandler.o utils/FileHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/utils/FileHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/FileHandler_nomain.o utils/FileHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/utils/FileHandler.o ${OBJECTDIR}/utils/FileHandler_nomain.o;\
	fi

${OBJECTDIR}/utils/MathUtils_nomain.o: ${OBJECTDIR}/utils/MathUtils.o utils/MathUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/utils/MathUtils.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/MathUtils_nomain.o utils/MathUtils.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/utils/MathUtils.o ${OBJECTDIR}/utils/MathUtils_nomain.o;\
	fi

${OBJECTDIR}/utils/RandomNumberGenerator_nomain.o: ${OBJECTDIR}/utils/RandomNumberGenerator.o utils/RandomNumberGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/utils
	@NMOUTPUT=`${NM} ${OBJECTDIR}/utils/RandomNumberGenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/RandomNumberGenerator_nomain.o utils/RandomNumberGenerator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/utils/RandomNumberGenerator.o ${OBJECTDIR}/utils/RandomNumberGenerator_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
