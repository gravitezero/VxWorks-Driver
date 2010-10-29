# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMLINUXdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /media/daData/driver
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/PEDriver



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simlinux
CPU = SIMLINUX
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks68
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = PEDriver/$(MODE_DIR)/PEDriver.out \
	 PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage.o


#Rules

# PEDriver
ifeq ($(DEBUG_MODE),1)
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
PEDriver/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
PEDriver/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
PEDriver/$(MODE_DIR)/% : IDE_LIBRARIES = 
PEDriver/$(MODE_DIR)/% : PROJECT_TYPE = DKM
PEDriver/$(MODE_DIR)/% : DEFINES = 
PEDriver/$(MODE_DIR)/% : EXPAND_DBG = 0
PEDriver/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
PEDriver/$(MODE_DIR)/% : CPU = SIMLINUX
PEDriver/$(MODE_DIR)/% : TOOL_FAMILY = diab
PEDriver/$(MODE_DIR)/% : TOOL = diab
PEDriver/$(MODE_DIR)/% : TOOL_PATH = 
PEDriver/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks68
PEDriver/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
PEDriver/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
PEDriver/$(MODE_DIR)/% : LIBPATH = 
PEDriver/$(MODE_DIR)/% : LIBS = 
PEDriver/$(MODE_DIR)/% : OBJ_DIR := PEDriver/$(MODE_DIR)

OBJECTS_PEDriver = PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage.o

PEDriver/$(MODE_DIR)/PEDriver.out : $(OBJECTS_PEDriver)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_PEDriver) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium -tags $(VSB_DIR)/tags/simlinux/SIMLINUX/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks68 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_PEDriver) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

PEDriver/$(MODE_DIR)/PEDriver_compile_file : $(FILE) ;

_clean :: PEDriver/$(MODE_DIR)/PEDriver_clean

PEDriver/$(MODE_DIR)/PEDriver_clean : 
	$(TRACE_FLAG)if [ -d "PEDriver" ]; then cd "PEDriver"; rm -rf $(MODE_DIR); fi


# PEDriver_partialImage
ifeq ($(DEBUG_MODE),1)
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
PEDriver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
PEDriver_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
PEDriver_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
PEDriver_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
PEDriver_partialImage/$(MODE_DIR)/% : DEFINES = 
PEDriver_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
PEDriver_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
PEDriver_partialImage/$(MODE_DIR)/% : CPU = SIMLINUX
PEDriver_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
PEDriver_partialImage/$(MODE_DIR)/% : TOOL = diab
PEDriver_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
PEDriver_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks68
PEDriver_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
PEDriver_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
PEDriver_partialImage/$(MODE_DIR)/% : LIBPATH = 
PEDriver_partialImage/$(MODE_DIR)/% : LIBS = 
PEDriver_partialImage/$(MODE_DIR)/% : OBJ_DIR := PEDriver_partialImage/$(MODE_DIR)

PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/driver.o : $(PRJ_ROOT_DIR)/driver.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/unittest.o : $(PRJ_ROOT_DIR)/unittest.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


OBJECTS_PEDriver_partialImage = PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/driver.o \
	 PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/unittest.o

PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage.o : $(OBJECTS_PEDriver_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks68 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_PEDriver_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage_compile_file : $(FILE) ;

_clean :: PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage_clean

PEDriver_partialImage/$(MODE_DIR)/PEDriver_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "PEDriver_partialImage" ]; then cd "PEDriver_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/driver.d PEDriver_partialImage/$(MODE_DIR)/Objects/PEDriver/unittest.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
