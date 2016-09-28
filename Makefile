CC=g++
CFLAGS=-c -Wall

all: pascal

pascal: pascal.o errors.o source_buffer.o TextInBuffer.o
	$(CC) pascal.o errors.o source_buffer.o TextInBuffer.o -o pascal

pascal.o: pascal.cpp
	$(CC) $(CFLAGS) pascal.cpp

errors.o: errors.cpp
	$(CC) $(CFLAGS) errors.cpp

source_buffer.o: source_buffer.cpp
	$(CC) $(CFLAGS) source_buffer.cpp

TextInBuffer.o: TextInBuffer.cpp
	$(CC) $(CFLAGS) TextInBuffer.cpp

clean:
	rm *o pascal