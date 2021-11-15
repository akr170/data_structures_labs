CC = g++
CPPFLAGS = -Wall -g -std=c++11
OBJTS = app.o website.o table.o

app:			$(OBJTS)

app.o:			website.h table.h

website.o:		website.h

table.o:		table.h

.PHONY: clean	
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f app
