CC  = g++
CXX = g++
LD  = g++

LEX = flex
YACC = bison

RM = rm -rf

OPTIM_FLAGS = -O0 #-Os -flto
DEBUG_FLAGS = -g
OTHER_FLAGS = -MD

FLAGS  = $(OPTIM_FLAGS)
FLAGS += $(DEBUG_FLAGS)
FLAGS += $(OTHER_FLAGS)

CFLAGS 	 = $(FLAGS)
CXXFLAGS = $(FLAGS)
LDFLAGS  = $(FLAGS)

OBJS = GCodeGrammar.tab.o GCodeLexer.o GCodeScanner.o  main.o
MAIN_TARGET = main.out

LEX_FILES = GCodeScanner.l

# Main -------------------------

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^
	strip $@

%.tab.o: %.y
	$(YACC) $<

# Clean -------------------------

clean_temp:
	$(RM) $(OBJS) $(LEX_FILES:.l=.c) *.d *.tab.cc *.tab.hh stack.hh

clean: clean_temp
	$(RM) main.out

-include $(OBJS:.o=.d)

.PHONY: all clean
