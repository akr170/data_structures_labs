CC = g++
CPPFLAGS = -Wall -g -std=c++11
OBJTS = app.o website.o bst.o

app:            $(OBJTS)

app.o:          website.h bst.h

website.o:      website.h

bst.o:          bst.h

.PHONY: clean	
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f app
