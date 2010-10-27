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

BUILD_SPEC = SIMNTdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := Z:/Driver
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/test



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks67
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
PROJECT_TARGETS = test/$(MODE_DIR)/test.out \
	 test_partialImage/$(MODE_DIR)/test_partialImage.o


#Rules

# test
ifeq ($(DEBUG_MODE),1)
test/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
test/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
test/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
test/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
test/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
test/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
test/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
test/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
test/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
test/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
test/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
test/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
test/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
test/$(MODE_DIR)/% : IDE_LIBRARIES = 
test/$(MODE_DIR)/% : PROJECT_TYPE = DKM
test/$(MODE_DIR)/% : DEFINES = 
test/$(MODE_DIR)/% : EXPAND_DBG = 0
test/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
test/$(MODE_DIR)/% : CPU = SIMNT
test/$(MODE_DIR)/% : TOOL_FAMILY = diab
test/$(MODE_DIR)/% : TOOL = diab
test/$(MODE_DIR)/% : TOOL_PATH = 
test/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
test/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
test/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
test/$(MODE_DIR)/% : LIBPATH = 
test/$(MODE_DIR)/% : LIBS = 
test/$(MODE_DIR)/% : OBJ_DIR := test/$(MODE_DIR)

OBJECTS_test = test_partialImage/$(MODE_DIR)/test_partialImage.o

test/$(MODE_DIR)/test.out : $(OBJECTS_test)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_test) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_test) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

test/$(MODE_DIR)/test_compile_file : $(FILE) ;

_clean :: test/$(MODE_DIR)/test_clean

test/$(MODE_DIR)/test_clean : 
	$(TRACE_FLAG)if [ -d "test" ]; then cd "test"; rm -rf $(MODE_DIR); fi


# test_partialImage
ifeq ($(DEBUG_MODE),1)
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
test_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
test_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
test_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
test_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
test_partialImage/$(MODE_DIR)/% : DEFINES = 
test_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
test_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
test_partialImage/$(MODE_DIR)/% : CPU = SIMNT
test_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
test_partialImage/$(MODE_DIR)/% : TOOL = diab
test_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
test_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
test_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
test_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
test_partialImage/$(MODE_DIR)/% : LIBPATH = 
test_partialImage/$(MODE_DIR)/% : LIBS = 
test_partialImage/$(MODE_DIR)/% : OBJ_DIR := test_partialImage/$(MODE_DIR)

test_partialImage/$(MODE_DIR)/Objects/test/driver.o : $(PRJ_ROOT_DIR)/driver.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


test_partialImage/$(MODE_DIR)/Objects/test/main.o : $(PRJ_ROOT_DIR)/main.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


OBJECTS_test_partialImage = test_partialImage/$(MODE_DIR)/Objects/test/driver.o \
	 test_partialImage/$(MODE_DIR)/Objects/test/main.o

test_partialImage/$(MODE_DIR)/test_partialImage.o : $(OBJECTS_test_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_test_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

test_partialImage/$(MODE_DIR)/test_partialImage_compile_file : $(FILE) ;

_clean :: test_partialImage/$(MODE_DIR)/test_partialImage_clean

test_partialImage/$(MODE_DIR)/test_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "test_partialImage" ]; then cd "test_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := test_partialImage/$(MODE_DIR)/Objects/test/driver.d test_partialImage/$(MODE_DIR)/Objects/test/main.d
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
