#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/temporalrank.o \
	${OBJECTDIR}/locationact.o \
	${OBJECTDIR}/interestact.o \
	${OBJECTDIR}/Enactage.o \
	${OBJECTDIR}/IsImplies.o \
	${OBJECTDIR}/LeeMain.o \
	${OBJECTDIR}/Enact.o \
	${OBJECTDIR}/enactEL.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Release/GNU-Linux-x86/leeinterpreter

dist/Release/GNU-Linux-x86/leeinterpreter: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/leeinterpreter ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/temporalrank.o: temporalrank.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/temporalrank.o temporalrank.cc

${OBJECTDIR}/locationact.o: locationact.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/locationact.o locationact.cc

${OBJECTDIR}/interestact.o: interestact.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/interestact.o interestact.cc

${OBJECTDIR}/Enactage.o: Enactage.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/Enactage.o Enactage.cc

${OBJECTDIR}/IsImplies.o: IsImplies.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/IsImplies.o IsImplies.cc

${OBJECTDIR}/LeeMain.o: LeeMain.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/LeeMain.o LeeMain.cc

${OBJECTDIR}/Enact.o: Enact.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/Enact.o Enact.cc

${OBJECTDIR}/enactEL.o: enactEL.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -O2 -o ${OBJECTDIR}/enactEL.o enactEL.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/leeinterpreter

# Subprojects
.clean-subprojects:
