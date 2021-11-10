CC = g++
CPPFLAGS = -Wall -g -std=c++11

main:			main.o dlist.o supplied.o

main.o:			dlist.h

dlist.o:		dlist.h

.PHONY: clean	
clean:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f dlist.o main.o main
