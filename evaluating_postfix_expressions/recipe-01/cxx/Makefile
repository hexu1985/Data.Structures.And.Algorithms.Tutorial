CXX = g++
CXXFLAGS = -g3 -Wall -Wextra
INCLUDES = 
LDFLAGS = 
LDLIBS = 

PROGS =	tokens_test

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

tokens_test: tokens_test.cpp print.hpp tokens.hpp
	$(CXX) -o $@ tokens_test.cpp $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

