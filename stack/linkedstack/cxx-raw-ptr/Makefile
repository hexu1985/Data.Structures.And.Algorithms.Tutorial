CXX = g++
CXXFLAGS = -g3 -Wall -Wextra -fsanitize=leak -fno-omit-frame-pointer
LDFLAGS = -lasan
LDLIBS =

SOURCES = $(shell ls *.cpp)
TARGETS = $(subst .cpp,,$(SOURCES))
#TARGETS = $(SOURCES:%.cpp=%)

all: $(TARGETS)
	@echo "TARGETS = $(TARGETS)" 

.PHONY:
clean:
	$(RM) $(TARGETS) a.out core *.o
	@echo "clean OK!"
