SRC = $(wildcard src/*.cpp)
OBJ = ${SRC:.cpp=.o}

CC = clang++
CFLAGS = -c -Wall -Wno-char-subscripts
LDFLAGS += -lm

clang = $(shell which clang 2> /dev/null)
ifeq (, $(clang))
	CC = gcc
endif

# output

OUT = pascal

$(OUT): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	@$(CC) -c $(CFLAGS) $< -o $@
	@printf "\e[36mCC\e[90m %s\e[0m\n" $@

clean:
	rm -f pascal $(OBJ)