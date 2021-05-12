CC  = g++
CXX = g++
LD  = g++

RM = rm -rf

OPTIM_FLAGS = -O0 #-Os -flto
DEBUG_FLAGS = -g
OTHER_FLAGS = -MD
LIB_FLAGS   = -I. -I..

FLAGS  = $(OPTIM_FLAGS)
FLAGS += $(DEBUG_FLAGS)
FLAGS += $(OTHER_FLAGS)
FLAGS += $(LIB_FLAGS)

CFLAGS 	 = $(FLAGS)
CXXFLAGS = $(FLAGS)
LDFLAGS  = $(FLAGS)

OBJS = libuart.o debug_func.o main.o 
MAIN_TARGET = main.out
LIB_NAME = uart

# Main -------------------------

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^
	#strip $@

build_lib: __build_lib

__build_lib: $(OBJS)
	$(AR) rc lib$(LIB_NAME).a $(OBJS)

# Clean -------------------------

clean_temp:
	$(RM) $(OBJS) $(LEX_FILES:.l=.c) *.d *.tab.cc *.tab.hh stack.hh

clean: clean_temp
	$(RM) main.out lib$(LIB_NAME).a

-include $(OBJS:.o=.d)

.PHONY: all clean