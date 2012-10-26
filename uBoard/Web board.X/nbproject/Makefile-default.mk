#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/Delay.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Patterns.o ${OBJECTDIR}/_ext/1472/Peripherals.o ${OBJECTDIR}/_ext/1472/Socket.o ${OBJECTDIR}/_ext/1472/W5100.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/Delay.o.d ${OBJECTDIR}/_ext/1472/Main.o.d ${OBJECTDIR}/_ext/1472/Patterns.o.d ${OBJECTDIR}/_ext/1472/Peripherals.o.d ${OBJECTDIR}/_ext/1472/Socket.o.d ${OBJECTDIR}/_ext/1472/W5100.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Delay.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Patterns.o ${OBJECTDIR}/_ext/1472/Peripherals.o ${OBJECTDIR}/_ext/1472/Socket.o ${OBJECTDIR}/_ext/1472/W5100.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ64GP802
MP_LINKER_FILE_OPTION=,--script="..\p33FJ64GP802.application.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.ok ${OBJECTDIR}/_ext/1472/Delay.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Delay.o.d" -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c  
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.ok ${OBJECTDIR}/_ext/1472/Main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	
${OBJECTDIR}/_ext/1472/Patterns.o: ../Patterns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.ok ${OBJECTDIR}/_ext/1472/Patterns.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Patterns.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Patterns.o.d" -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c  
	
${OBJECTDIR}/_ext/1472/Peripherals.o: ../Peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ${OBJECTDIR}/_ext/1472/Peripherals.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Peripherals.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Peripherals.o.d" -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c  
	
${OBJECTDIR}/_ext/1472/Socket.o: ../Socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.ok ${OBJECTDIR}/_ext/1472/Socket.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Socket.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Socket.o.d" -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c  
	
${OBJECTDIR}/_ext/1472/W5100.o: ../W5100.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.ok ${OBJECTDIR}/_ext/1472/W5100.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/W5100.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/W5100.o.d" -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c  
	
else
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.ok ${OBJECTDIR}/_ext/1472/Delay.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Delay.o.d" -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c  
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.ok ${OBJECTDIR}/_ext/1472/Main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	
${OBJECTDIR}/_ext/1472/Patterns.o: ../Patterns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.ok ${OBJECTDIR}/_ext/1472/Patterns.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Patterns.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Patterns.o.d" -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c  
	
${OBJECTDIR}/_ext/1472/Peripherals.o: ../Peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ${OBJECTDIR}/_ext/1472/Peripherals.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Peripherals.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Peripherals.o.d" -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c  
	
${OBJECTDIR}/_ext/1472/Socket.o: ../Socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.ok ${OBJECTDIR}/_ext/1472/Socket.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Socket.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/Socket.o.d" -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c  
	
${OBJECTDIR}/_ext/1472/W5100.o: ../W5100.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.ok ${OBJECTDIR}/_ext/1472/W5100.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/W5100.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -ansi -Werror -Wall -pedantic -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/W5100.o.d" -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1,--heap=64,-L"..",-Map="${DISTDIR}/Web_board.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1,--heap=64,-L"..",-Map="${DISTDIR}/Web_board.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
