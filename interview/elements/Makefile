CXXFLAGS := -Wall -Wextra -ansi -pedantic -pthread -std=c++11 -mtune=native

DEPS := $(wildcard *.h)

QUESTIONS_SRC :=$(wildcard *.cc)
QUESTIONS := $(patsubst %.cc,%.out,$(QUESTIONS_SRC))

all:  questions

fast: CXXFLAGS += -O3
fast: questions

debug: CXXFLAGS += -g
debug: questions


%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

questions: $(QUESTIONS)

test%.o: test%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.out: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *~ *.out *.o
