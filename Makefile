CXX=g++
CPPFLAGS=-Wall -g
CPPFLAGSREL=-O2 
CPPSTD= c++2a

BUILD_DIR=./build
RELEASE_DIR=$(BUILD_DIR)/release
NODEADCODE_DIR=$(BUILD_DIR)/nodeadcode

SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
OBJS_REL=$(patsubst %.cpp, $(RELEASE_DIR)/%.o, $(SRCS))
OBJS_NDC=$(patsubst %.cpp, $(NODEADCODE_DIR)/%.o, $(SRCS))


all: $(OBJS)

$(BUILD_DIR)/%.o: %.cpp $(BUILD_DIR)
	$(CXX) -std=$(CPPSTD) $(CPPFLAGS) $< -o $@

$(BUILD_DIR):
	mkdir -p $@

release: $(OBJS_REL)

$(RELEASE_DIR)/%.o: %.cpp $(RELEASE_DIR)
		$(CXX) -std=$(CPPSTD) $(CPPFLAGSREL) $< -o $@

$(RELEASE_DIR):
	mkdir -p $@


nodeadcode: $(OBJS_NDC)

$(NODEADCODE_DIR)/%.o: %.cpp $(NODEADCODE_DIR)
		$(CXX) -std=$(CPPSTD) -ffunction-sections -fdata-sections $< -o $@
		$(CXX) -std=$(CPPSTD) $< -o $@ -Wl,--gc-sections
#removes unused sections of code

$(NODEADCODE_DIR):
	mkdir -p $@

clean:
	$(RM) $(BUILD_DIR)/*.o
	$(RM) $(RELEASE_DIR)/*.o
	$(RM) $(NODEADCODE_DIR)/*.o