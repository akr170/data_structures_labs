CC = g++
CPPFLAGS = -Wall -g -std=c++11
OBJTS = app.o song.o songlist.o

app:			$(OBJTS)

app.o:			song.h songlist.h

song.o:			song.h

songlist.o:		songlist.h

.PHONY: clean	
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f app
