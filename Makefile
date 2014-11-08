CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o book.o list.o loadfile.o booksort.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o assignment

main.o: book.h list.h loadfile.h
	$(CC) $(CFLAGS) main.cpp

book.o: book.h
	$(CC) $(CFLAGS) book.cpp

list.o: list.h
	$(CC) $(CFLAGS) list.cpp

loadfile.o: loadfile.h
	$(CC) $(CFLAGS) loadfile.cpp
    
booksort.o: booksort.h
    $(CC) $(CFLAGS) booksort.cpp

clean:
	rm *.o sort
