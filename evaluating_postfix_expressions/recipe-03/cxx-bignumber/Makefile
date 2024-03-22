CXX = g++
CXXFLAGS = -g3 -Wall -Wextra -std=c++17
INCLUDES = -IBigNumber/src
LDFLAGS = 
LDLIBS = 

PROGS =	tokens_test scanner_test evaluatorapp converter_test
BIGNUMBER_SRCS = BigNumber/src/bignumber.cpp

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

tokens_test: tokens_test.cpp print.hpp tokens.hpp $(BIGNUMBER_SRCS)
	$(CXX) -o $@ tokens_test.cpp $(BIGNUMBER_SRCS) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

scanner_test: scanner_test.cpp print.hpp scanner.hpp $(BIGNUMBER_SRCS)
	$(CXX) -o $@ scanner_test.cpp $(BIGNUMBER_SRCS) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

evaluatorapp: evaluatorapp.cpp print.hpp scanner.hpp $(BIGNUMBER_SRCS)
	$(CXX) -o $@ evaluatorapp.cpp $(BIGNUMBER_SRCS) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

converter_test: converter_test.cpp print.hpp converter.hpp $(BIGNUMBER_SRCS)
	$(CXX) -o $@ converter_test.cpp $(BIGNUMBER_SRCS) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

