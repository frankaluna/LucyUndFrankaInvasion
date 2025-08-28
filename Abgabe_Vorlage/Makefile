CXX := c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
GTEST_INCLUDES := -IGoogleTest/googletest/include -IGoogleTest/googletest \
			      -IGoogleTest/googlemock/include -IGoogleTest/googlemock
INCLUDES := -I./SFML/include -I/opt/homebrew/include $(GTEST_INCLUDES)

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS := -L/usr/local/lib -L./SFML/lib -L/opt/homebrew/lib
LDLIBS := -lsfml-system -lsfml-window -lsfml-graphics

SRCDIR := ./src
TESTDIR := ./test
BUILDDIR := ./build
VPATH := src

# search all .cpp files and add corresponding .o-files to GAME_OBJECTS
SRCFILES := $(shell find $(SRCDIR) -name '*.cpp')
TEST_SOURCES := $(shell find $(TESTDIR) $(SRCDIR)/model $(SRCDIR)/view $(SRCDIR)/control -name '*.cpp')
TEST_OBJECTS := $(patsubst %.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))
GAME_OBJECTS := $(SRCFILES:$(SRCDIR)/%.cpp=$(BUILDDIR)/src/%.o)
DEPENDENCIES := $(SRCFILES:$(SRCDIR)/%.cpp=$(BUILDDIR)/src/%.d) 

# build GTest
GTEST_DIR := GoogleTest
$(BUILDDIR)/gtest-all.o: $(GTEST_DIR)/googletest/src/gtest-all.cc
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest/include -I$(GTEST_DIR)/googletest $< -c -o $@
$(BUILDDIR)/gtest_main.o: $(GTEST_DIR)/googletest/src/gtest_main.cc
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest/include -I$(GTEST_DIR)/googletest $< -c -o $@
$(BUILDDIR)/gmock-all.o: $(GTEST_DIR)/googlemock/src/gmock-all.cc
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest/include -I$(GTEST_DIR)/googletest -I$(GTEST_DIR)/googlemock/include -I$(GTEST_DIR)/googlemock $< -c -o $@
$(BUILDDIR)/libgtest.a: $(BUILDDIR)/gtest-all.o $(BUILDDIR)/gtest_main.o
	ar rcs $@ $^
$(BUILDDIR)/libgmock.a: $(BUILDDIR)/gmock-all.o
	ar rcs $@ $^


# build game 
game: $(GAME_OBJECTS)
	$(CXX) $(GAME_OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

# build tests
TEST_BINARY := Test

tests: $(TEST_OBJECTS) $(BUILDDIR)/libgtest.a $(BUILDDIR)/libgmock.a
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(filter %.o,$^) -L$(BUILDDIR) -lgtest -lgmock -pthread -o $@  $(LDFLAGS) $(LDLIBS)
	
-include $(DEPENDENCIES)

getGTest:
	@echo "Downloading GoogleTest"
	curl -L https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz --output googletest-1.17.0.tar.gz
	@echo "Unpacking the lib"
	tar -xf googletest-1.17.0.tar.gz
	@echo "Removing download"
	rm googletest-1.17.0.tar.gz
	@echo "Renaming folder"
	mv googletest-1.17.0 GoogleTest
	@echo "Finished!"

# On a Mac: "brew install sfml" will install the library.
getSFML:
	@echo "Downloading SFML"
	curl https://www.sfml-dev.org/files/SFML-3.0.0-linux-gcc-64-bit.tar.gz --output SFML.tar.gz
	@echo "Unpacking the lib"
	tar -xf SFML.tar.gz
	@echo "Removing download"
	rm SFML.tar.gz
	@echo "Renaming folder"
	mv SFML-3.0.0 SFML
	@echo "Finished!"
    
$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(BUILDDIR)/src $(BUILDDIR)/test game tests
