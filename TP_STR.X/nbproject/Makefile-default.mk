#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
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
FINAL_IMAGE=${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c systeme.c T1.c T2.c T3.c T4.c T5.c T6.c afficheur.c semaphore.c stid.c rxtx.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/systeme.p1 ${OBJECTDIR}/T1.p1 ${OBJECTDIR}/T2.p1 ${OBJECTDIR}/T3.p1 ${OBJECTDIR}/T4.p1 ${OBJECTDIR}/T5.p1 ${OBJECTDIR}/T6.p1 ${OBJECTDIR}/afficheur.p1 ${OBJECTDIR}/semaphore.p1 ${OBJECTDIR}/stid.p1 ${OBJECTDIR}/rxtx.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/systeme.p1.d ${OBJECTDIR}/T1.p1.d ${OBJECTDIR}/T2.p1.d ${OBJECTDIR}/T3.p1.d ${OBJECTDIR}/T4.p1.d ${OBJECTDIR}/T5.p1.d ${OBJECTDIR}/T6.p1.d ${OBJECTDIR}/afficheur.p1.d ${OBJECTDIR}/semaphore.p1.d ${OBJECTDIR}/stid.p1.d ${OBJECTDIR}/rxtx.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/systeme.p1 ${OBJECTDIR}/T1.p1 ${OBJECTDIR}/T2.p1 ${OBJECTDIR}/T3.p1 ${OBJECTDIR}/T4.p1 ${OBJECTDIR}/T5.p1 ${OBJECTDIR}/T6.p1 ${OBJECTDIR}/afficheur.p1 ${OBJECTDIR}/semaphore.p1 ${OBJECTDIR}/stid.p1 ${OBJECTDIR}/rxtx.p1

# Source Files
SOURCEFILES=main.c systeme.c T1.c T2.c T3.c T4.c T5.c T6.c afficheur.c semaphore.c stid.c rxtx.c



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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F87K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/systeme.p1: systeme.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/systeme.p1.d 
	@${RM} ${OBJECTDIR}/systeme.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/systeme.p1 systeme.c 
	@-${MV} ${OBJECTDIR}/systeme.d ${OBJECTDIR}/systeme.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/systeme.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T1.p1: T1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T1.p1.d 
	@${RM} ${OBJECTDIR}/T1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T1.p1 T1.c 
	@-${MV} ${OBJECTDIR}/T1.d ${OBJECTDIR}/T1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T2.p1: T2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T2.p1.d 
	@${RM} ${OBJECTDIR}/T2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T2.p1 T2.c 
	@-${MV} ${OBJECTDIR}/T2.d ${OBJECTDIR}/T2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T3.p1: T3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T3.p1.d 
	@${RM} ${OBJECTDIR}/T3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T3.p1 T3.c 
	@-${MV} ${OBJECTDIR}/T3.d ${OBJECTDIR}/T3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T4.p1: T4.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T4.p1.d 
	@${RM} ${OBJECTDIR}/T4.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T4.p1 T4.c 
	@-${MV} ${OBJECTDIR}/T4.d ${OBJECTDIR}/T4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T5.p1: T5.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T5.p1.d 
	@${RM} ${OBJECTDIR}/T5.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T5.p1 T5.c 
	@-${MV} ${OBJECTDIR}/T5.d ${OBJECTDIR}/T5.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T5.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T6.p1: T6.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T6.p1.d 
	@${RM} ${OBJECTDIR}/T6.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T6.p1 T6.c 
	@-${MV} ${OBJECTDIR}/T6.d ${OBJECTDIR}/T6.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T6.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/afficheur.p1: afficheur.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/afficheur.p1.d 
	@${RM} ${OBJECTDIR}/afficheur.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/afficheur.p1 afficheur.c 
	@-${MV} ${OBJECTDIR}/afficheur.d ${OBJECTDIR}/afficheur.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/afficheur.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/semaphore.p1: semaphore.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/semaphore.p1.d 
	@${RM} ${OBJECTDIR}/semaphore.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/semaphore.p1 semaphore.c 
	@-${MV} ${OBJECTDIR}/semaphore.d ${OBJECTDIR}/semaphore.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/semaphore.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stid.p1: stid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stid.p1.d 
	@${RM} ${OBJECTDIR}/stid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/stid.p1 stid.c 
	@-${MV} ${OBJECTDIR}/stid.d ${OBJECTDIR}/stid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/rxtx.p1: rxtx.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rxtx.p1.d 
	@${RM} ${OBJECTDIR}/rxtx.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/rxtx.p1 rxtx.c 
	@-${MV} ${OBJECTDIR}/rxtx.d ${OBJECTDIR}/rxtx.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/rxtx.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/systeme.p1: systeme.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/systeme.p1.d 
	@${RM} ${OBJECTDIR}/systeme.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/systeme.p1 systeme.c 
	@-${MV} ${OBJECTDIR}/systeme.d ${OBJECTDIR}/systeme.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/systeme.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T1.p1: T1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T1.p1.d 
	@${RM} ${OBJECTDIR}/T1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T1.p1 T1.c 
	@-${MV} ${OBJECTDIR}/T1.d ${OBJECTDIR}/T1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T2.p1: T2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T2.p1.d 
	@${RM} ${OBJECTDIR}/T2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T2.p1 T2.c 
	@-${MV} ${OBJECTDIR}/T2.d ${OBJECTDIR}/T2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T3.p1: T3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T3.p1.d 
	@${RM} ${OBJECTDIR}/T3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T3.p1 T3.c 
	@-${MV} ${OBJECTDIR}/T3.d ${OBJECTDIR}/T3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T4.p1: T4.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T4.p1.d 
	@${RM} ${OBJECTDIR}/T4.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T4.p1 T4.c 
	@-${MV} ${OBJECTDIR}/T4.d ${OBJECTDIR}/T4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T5.p1: T5.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T5.p1.d 
	@${RM} ${OBJECTDIR}/T5.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T5.p1 T5.c 
	@-${MV} ${OBJECTDIR}/T5.d ${OBJECTDIR}/T5.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T5.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/T6.p1: T6.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/T6.p1.d 
	@${RM} ${OBJECTDIR}/T6.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/T6.p1 T6.c 
	@-${MV} ${OBJECTDIR}/T6.d ${OBJECTDIR}/T6.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/T6.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/afficheur.p1: afficheur.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/afficheur.p1.d 
	@${RM} ${OBJECTDIR}/afficheur.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/afficheur.p1 afficheur.c 
	@-${MV} ${OBJECTDIR}/afficheur.d ${OBJECTDIR}/afficheur.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/afficheur.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/semaphore.p1: semaphore.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/semaphore.p1.d 
	@${RM} ${OBJECTDIR}/semaphore.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/semaphore.p1 semaphore.c 
	@-${MV} ${OBJECTDIR}/semaphore.d ${OBJECTDIR}/semaphore.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/semaphore.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stid.p1: stid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stid.p1.d 
	@${RM} ${OBJECTDIR}/stid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/stid.p1 stid.c 
	@-${MV} ${OBJECTDIR}/stid.d ${OBJECTDIR}/stid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/rxtx.p1: rxtx.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rxtx.p1.d 
	@${RM} ${OBJECTDIR}/rxtx.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)      -o ${OBJECTDIR}/rxtx.p1 rxtx.c 
	@-${MV} ${OBJECTDIR}/rxtx.d ${OBJECTDIR}/rxtx.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/rxtx.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=pickit3  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/TP_STR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
