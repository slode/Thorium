CXX = g++
CXXFLAGS ?= -g -W -ansi -Wall -Iinclude/# -pedantic
CXXFLAGS = -ansi -Iinclude/
LDFLAGS ?= -lSDL -lGL
SED = sed
MV = mv
RM = rm

.SUFFIXES: .o .cpp

SRC = src
TESTS = tests
OBJ = obj
BIN = bin

LIB = lib/libUnitTest++.a
TEST = $(BIN)/thorium_tests
EXE = $(BIN)/thorium


DEPS = $(wildcard $(SRC)/*cpp)
TEST_SRC = $(wildcard $(TESTS)/*.cpp)

OBJECTS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(DEPS))
TEST_OBJECTS = $(patsubst %.cpp, %.o, $(TEST_SRC))

all: $(TEST) $(EXE)

$(EXE): $(OBJECTS)
	@echo Linking $(EXE)...
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(EXE)
 

$(TEST): $(TEST_OBJECTS)
	@echo Linking $(TEST)...
	@$(CXX) $(LDFLAGS) -o $(TEST) $(TEST_OBJECTS) $(LIB)
	-@$(RM) $(TEST_OBJECTS) 2> /dev/null
	@echo Running unit tests...
	@./$(TEST)

$(OBJECTS): $(DEPS)
	@echo Compiling $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cpp
	@echo Compiling $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-@$(RM) $(OBJECTS) $(TEST_OBJECTS) $(TEST) $(EXE) 2> /dev/null


