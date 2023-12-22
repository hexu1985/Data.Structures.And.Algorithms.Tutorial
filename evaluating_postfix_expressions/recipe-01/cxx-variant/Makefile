CXX = g++
CXXFLAGS = -g3 -Wall -Wextra -std=c++17
INCLUDES = 
LDFLAGS = 
LDLIBS = 

PROGS =	tokens_test scanner_test evaluatorapp

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

tokens_test: tokens_test.cpp print.hpp tokens.hpp
	$(CXX) -o $@ tokens_test.cpp $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

scanner_test: scanner_test.cpp print.hpp scanner.hpp
	$(CXX) -o $@ scanner_test.cpp $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

evaluatorapp: evaluatorapp.cpp print.hpp scanner.hpp
	$(CXX) -o $@ evaluatorapp.cpp $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

