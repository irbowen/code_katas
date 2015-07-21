CXXFLAGS := -Wall -g -std=c++11 

DEPS := $(wildcard *.h)

QUESTIONS_SRC :=$(wildcard *.cpp)
QJESTIONS := $(patsubst %.cpp,%.out,$(QUESTIONS_SRC))

all:  questions

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

fileserver:  $(FS_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FS_OBJS) 

questions: $(QJESTIONS)

test%.o: test%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.out: %.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *~ *.out *.o fileserver
