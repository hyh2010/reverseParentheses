CPP = g++
CPPFLAGS += -Wall -Weffc++ -std=c++11

SRC_PATH = ..

OBJ_SUFFIX = o

UTEST = utest_reverseParentheses
UTEST_TARGET = $(UTEST)

SOURCES = $(SRC_PATH)/topDownParser.cpp $(SRC_PATH)/reverseParentheses.cpp
OBJECTS = $(SOURCES:.cpp=.$(OBJ_SUFFIX))

UTEST_SOURCES = utest_reverseParentheses.cpp
UTEST_OBJECTS = $(UTEST_SOURCES:.cpp=.$(OBJ_SUFFIX))

all: build
debug: CPPFLAGS += -g
debug: build
build: $(UTEST_TARGET)

clean:
	$(RM) $(OBJECTS) $(UTEST_TARGET) $(UTEST_OBJECTS)

GTEST_ROOT = /home/hyh/googletest/latest
GTEST_DIR = $(GTEST_ROOT)/googletest
GTEST_LIB_DIR = $(GTEST_ROOT)/lib

CPPFLAGS += -I $(SRC_PATH) -I $(GTEST_DIR)/include

TESTLIBS = $(GTEST_LIB_DIR)/libgtest.a  $(GTEST_LIB_DIR)/libgtest_main.a -lpthread

$(UTEST_TARGET): $(UTEST_OBJECTS) $(OBJECTS)
	$(CPP) $(LDFLAGS) -o $(UTEST_TARGET) $(OBJECTS) $(UTEST_OBJECTS) $(TESTLIBS)
