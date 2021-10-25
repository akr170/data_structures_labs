CC = g++
CPPFLAGS = -Wall -g -std=c++11
OBJTS = app.o customer.o customerinfo.o queue.o stack.o

app:			$(OBJTS)

app.o:			customer.h customerinfo.h queue.h stack.h

customer.o:		customer.h

customerinfo.o: customerinfo.h

queue.o:		queue.h

stack.o:		stack.h

.PHONY: clean	
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f app
