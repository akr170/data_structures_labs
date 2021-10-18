CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:			app.o table.o supplied.o

app.o:			table.h

table.o:		table.h

.PHONY: clean	
clean:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f clist.o app.o app
