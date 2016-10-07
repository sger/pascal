CC=clang++
CFLAGS=-c -Wall

all: pascal

pascal: pascal.o errors.o source_buffer.o text_in_buffer.o text_out_buffer.o list_buffer.o common.o scanner.o text_scanner.o parser.o
	$(CC) pascal.o errors.o source_buffer.o text_in_buffer.o text_out_buffer.o list_buffer.o common.o scanner.o text_scanner.o parser.o -o pascal

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

scanner.o: scanner.cpp
	$(CC) $(CFLAGS) scanner.cpp

text_scanner.o: text_scanner.cpp
	$(CC) $(CFLAGS) text_scanner.cpp

parser.o: parser.cpp
	$(CC) $(CFLAGS) parser.cpp

clean:
	rm *o pascal