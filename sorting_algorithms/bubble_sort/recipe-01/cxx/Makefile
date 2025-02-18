CXX = g++
CXXFLAGS = -g3 -Wall -Wextra
INCLUDES = -I$(HOME)/local/googletest/include
LDFLAGS = -lgtest -lpthread
LDPATH = -L$(HOME)/local/googletest/lib

PROGS =	sample_bubble_sort sample_bubble_sort_with_tweak test_bubble_sort

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

sample_bubble_sort: sample_bubble_sort.cpp
	$(CXX) -o $@ $(CXXFLAGS) $^ 

sample_bubble_sort_with_tweak: sample_bubble_sort_with_tweak.cpp 
	$(CXX) -o $@ $(CXXFLAGS) $^ 

test_bubble_sort: test_bubble_sort.cpp random.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)

