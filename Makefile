#
# Makefile for Melody Maker 
#
CXX = clang++
FLAGS = -Wall -Wextra -g

all: Beep.cpp Beep.h Note.cpp Note.h main.cpp \
	   Melody.cpp Melody.h helperfuncs.cpp helperfuncs.h \
	   Queue.cpp Queue.h Stack.cpp Stack.h
	${CXX} ${FLAGS} -o melodymaker  `sdl-config --cflags --libs` \
           Beep.cpp Note.cpp helperfuncs.cpp Queue.cpp \
	   Melody.cpp Stack.cpp main.cpp

clean:
	rm -f melodymaker


