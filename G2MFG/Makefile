
CC  = g++
CXX = g++
LD  = g++

RM = rm -rf

OPTIM_FLAGS = -O0 #-Os -flto
DEBUG_FLAGS = -g
OTHER_FLAGS = -MD
LIB_FLAGS   = -I. -I./GCode -I./UART

FLAGS  = $(OPTIM_FLAGS)
FLAGS += $(DEBUG_FLAGS)
FLAGS += $(OTHER_FLAGS)
FLAGS += $(LIB_FLAGS)

CFLAGS 	 = $(FLAGS)
CXXFLAGS = $(FLAGS)
LDFLAGS  = $(FLAGS)

DIR_GCODE 	= GCode
DIR_MFGCODE = MFGCode
DIR_INV_KIN = InverseKinematic
DIR_UART 	= UART

LIB_DIRS  = $(DIR_GCODE)
LIB_DIRS += $(DIR_MFGCODE)
LIB_DIRS += $(DIR_INV_KIN)
LIB_DIRS += $(DIR_UART)

LIB_GCODE 	= gcode
LIB_MFGCODE = mfgcode
LIB_INV_KIN = invkin
LIB_UART 	= uart

LIBS  = $(LIB_GCODE)
LIBS += $(LIB_MFGCODE)
LIBS += $(LIB_INV_KIN)
LIBS += $(LIB_UART)

OBJS = main.o
MAIN_TARGET = main.out

# Main -------------------------

all: all_lib $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS)
	$(LD)  -o $@ $^ $(CXXFLAGS) $(LIB_DIRS:%=-L./%) $(LIBS:%=-l%)
	#strip $@

all_lib: gcode_lib mfgcode_lib invkin_lib uart_lib

gcode_lib:
	$(MAKE) -C $(DIR_GCODE)   build_lib

mfgcode_lib:
	$(MAKE) -C $(DIR_MFGCODE) build_lib

invkin_lib:
	$(MAKE) -C $(DIR_INV_KIN) build_lib

uart_lib:
	$(MAKE) -C $(DIR_UART)	  build_lib

# Clean -------------------------

clean_libs: clean_gcode_lib clean_mfgcode_lib clean_invkin_lib clean_uart_lib

clean_gcode_lib:
	$(MAKE) -C $(DIR_GCODE)   clean

clean_mfgcode_lib:
	$(MAKE) -C $(DIR_MFGCODE) clean

clean_invkin_lib:
	$(MAKE) -C $(DIR_INV_KIN) clean

clean_uart_lib:
	$(MAKE) -C $(DIR_UART)	  clean

clean_temp:
	$(RM) $(OBJS) $(LEX_FILES:.l=.c) *.d

clean: clean_temp clean_libs
	$(RM) main.out lib$(LIB_NAME).a

-include $(OBJS:.o=.d)

.PHONY: all clean build_lib __build_lib gcode_lib mfgcode_lib invkin_lib uart_lib