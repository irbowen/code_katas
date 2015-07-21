CXXFLAGS := -Wall -g -std=c++11 
LDFLAGS := -ldl -pthread

DEPS := $(wildcard *.h)

all: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

fileserver:  $(FS_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FS_OBJS) $(LDFLAGS)

tests: $(TESTS)

test%.o: test%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test%.out: test%.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TEST_OBS) $(LDFLAGS)

clean:
	rm -f *~ *.out *.o 
