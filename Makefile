CXX=g++
CXXFLAGS= -g -Wall -std=c++2a
SRC=src
OBJ=obj
INCLUDE=include
INCLUDES=$(wildcard $(INCLUDE)/*.h)
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))


LIB=lib
LIBNAME=libdatastructure.so
BINDIR=bin
BINS=libdatastructure 
SUBMITNAME=data_structure.zip

TEST=test
TESTS=$(wildcard $(TEST)/*.cpp)
TESTBINS=$(patsubst $(TEST)/%.cpp, $(TEST)/bin/%, $(TESTS))


all: $(BINS)

libdatastructure:
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $(LIB)/$(LIBNAME) $(SRCS) -lm

release: CXXFLAGS=-Wall -O2 -DNDEBUG -std=c++2a
release: clean
release: $(BINS)

test:$(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done


$(TEST)/bin/%: $(TEST)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ -L $(LIB) -ldatastructure -lgtest -lpthread

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(LIB):
	mkdir $@



clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/* $(TEST)/bin/*

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BINDIR)

# Make shared library available at runtime
shared_library_available:
	export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(mkfile_dir)$(LIB)/
	echo $$LD_LIBRARY_PATH

