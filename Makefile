CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o book.o list.o loadfile.o bookSort.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o sort

main.o: book.h list.h loadfile.h
	$(CC) $(CFLAGS) main.cpp

book.o: book.h
	$(CC) $(CFLAGS) book.cpp

list.o: list.h
	$(CC) $(CFLAGS) list.cpp

loadfile.o: loadfile.h
	$(CC) $(CFLAGS) loadfile.cpp
    
bookSort.o: bookSort.h
	$(CC) $(CFLAGS) bookSort.cpp

clean:
	rm *.o sort
