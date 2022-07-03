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
BINS=libdatastructure compile_tests
SUBMITNAME=data_structure.zip

all: $(BINS)

release: CXXFLAGS=-Wall -O2 -DNDEBUG -std=c++2a
release: clean
release: $(BINS)

libtest: compile_tests
libtest: clean
libtest:$(BINS)

libdatastructure:
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $(LIB)/$(LIBNAME) $(SRCS) -lm
libdatastructure:shared_library_available

compile_tests: 
	$(CXX) $(CXXFLAGS) $(SRC)/libtest.cc -o $(BINDIR)/libtest -I $(INCLUDE) -L $(LIB) -ldatastructure

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/* $(LIB)/*

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BINDIR)

# Make shared library available at runtime
shared_library_available:
	export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(mkfile_dir)$(LIB)/
	echo $$LD_LIBRARY_PATH