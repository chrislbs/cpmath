CC=g++
CCFLAGS=-std=c++0x -c
INCLUDEDIRS=include
SOURCES=src/cpfrac.cpp src/cpmath.cpp src/cpprime.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBRARY=bin/libcpmath.a

all: $(SOURCES) $(LIBRARY)

$(LIBRARY) : $(OBJECTS)
	ar rvs $(LIBRARY) $(OBJECTS)

.cpp.o:
	$(CC) $(CCFLAGS) $< -I $(INCLUDEDIRS) -o $@
