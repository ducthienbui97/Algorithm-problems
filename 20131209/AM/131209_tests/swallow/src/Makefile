CXX = g++
CXXFLAGS = -pipe -Wall -O2 -s

PROBLEM = swallow
TARGETS = e$(PROBLEM)
CLEANFILES = $(PROBLEM) *.in *.out *.o
CLEANFILES += e$(PROBLEM)

all: $(TARGETS)

e$(PROBLEM): $(PROBLEM).cpp
	$(CXX) -Wall -g -o eswallow swallow.cpp

$(PROBLEM): $(PROBLEM).cpp
	$(CXX) $(CXXFLAGS) -o swallow swallow.cpp

check-syntax:
	g++ -Wall -Wextra -Wno-sign-compare -fsyntax-only $(CHK_SOURCES)

clean:
	rm -f $(CLEANFILES)

.PHONY: all clean check-syntax
