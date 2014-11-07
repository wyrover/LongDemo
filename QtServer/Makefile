LIBS = -lboost_system

CFLAGS = -c -Wall -g

C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o,$(C_SRC))

CPP_SRC = $(wildcard *.cpp)
CPP_OBJ = $(patsubst, %cpp, %o, $(CPP_SRC))

.PHONY: all clean

all:$(CPP_OBJ) $(C_OBJ)

.c.o:
	gcc $(CFLAGS) -o $*.o $*.c $(LIBS)

.cpp.o:
	g++ $(CFLAGS) -o $*.o $*.cpp $(LIBS)

clean:
	rm -rf *.o
