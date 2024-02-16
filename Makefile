AR = ar
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O2 -march=x86-64 -fno-rtti
LDFLAGS = -s -static

SRC = StringSimilarity.cpp
OBJ = $(SRC:.cpp=.o)
DEST = StringSimilarity.a
TEST_SRC = StringSimilarityTest.cpp
TEST_DEST = StringSimilarityTest.exe

build: $(OBJ)
	$(AR) r -o $(DEST) $(OBJ)

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST)
