CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o book.o list.o loadfile.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o assignment
	rm *.o

main.o: book.h list.h loadfile.h
	$(CC) $(CFLAGS) main.cpp

book.o: book.h
	$(CC) $(CFLAGS) book.cpp

list.o: list.h
	$(CC) $(CFLAGS) list.cpp

loadfile.o: loadfile.h
	$(CC) $(CFLAGS) loadfile.cpp

clean:
	rm *.o main
