CC=clang++
CFLAGS=-c -Wall

all: pascal

pascal: pascal.o errors.o source_buffer.o text_in_buffer.o text_out_buffer.o list_buffer.o common.o
	$(CC) pascal.o errors.o source_buffer.o text_in_buffer.o text_out_buffer.o list_buffer.o common.o -o pascal

pascal.o: pascal.cpp
	$(CC) $(CFLAGS) pascal.cpp

errors.o: errors.cpp
	$(CC) $(CFLAGS) errors.cpp

source_buffer.o: source_buffer.cpp
	$(CC) $(CFLAGS) source_buffer.cpp

text_in_buffer.o: text_in_buffer.cpp
	$(CC) $(CFLAGS) text_in_buffer.cpp

text_out_buffer.o: text_out_buffer.cpp
	$(CC) $(CFLAGS) text_out_buffer.cpp

list_buffer.o: list_buffer.cpp
	$(CC) $(CFLAGS) list_buffer.cpp

common.o: common.cpp
	$(CC) $(CFLAGS) common.cpp

clean:
	rm *o pascal