CXX = g++
CXXFLAGS = -pipe -Wall -O2 -s

PROBLEM = mining
TARGETS = e$(PROBLEM)
CLEANFILES = $(PROBLEM) *.in *.out *.o
PRECOMPS = $(patsubst ../data/$(PROBLEM)%.in, ../data/e$(PROBLEM)%.in, $(wildcard ../data/$(PROBLEM)*.in))
TARGETS += $(PRECOMPS)
CLEANFILES += $(PRECOMPS)
GEN_ARGS =
GEN_ARGS += < $(PROBLEM).in
GEN_ARGS += > $(PROBLEM).out

all: $(TARGETS)

../data/e$(PROBLEM)%.in: ../data/$(PROBLEM)%.in $(PROBLEM)
	rm -f -- $(PROBLEM).in $(PROBLEM).out
	cp -- $< $(PROBLEM).in
	./$(PROBLEM) $(GEN_ARGS)
	mv -- $(PROBLEM).out $@
e$(PROBLEM): $(PRECOMPS) $(PROBLEM)
	touch -c $@
	chmod +x $@

$(PROBLEM): $(PROBLEM).cpp
	$(CXX) $(CXXFLAGS) -o mining mining.cpp

check-syntax:
	g++ -Wall -Wextra -Wno-sign-compare -fsyntax-only $(CHK_SOURCES)

clean:
	rm -f $(CLEANFILES)

.PHONY: all clean check-syntax
