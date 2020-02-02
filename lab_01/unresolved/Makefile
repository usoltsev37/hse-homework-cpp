.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -g -I include

all: lab1

clean:
	rm -rf bin lab1
bin:
	mkdir bin
bin/main.o: src/main.c include/algorithm.h include/io.h include/util.h | bin
	gcc $(CFLAGS) -c src/main.c -o bin/main.o
bin/algorithm.o: src/algorithm.c include/algorithm.h include/io.h include/util.h | bin
	gcc $(CFLAGS) -c src/algorithm.c -o bin/algorithm.o 
bin/util.o: src/util.c include/util.h include/io.h | bin
	gcc $(CFLAGS) -c src/util.c -o bin/util.o
bin/io.o: src/io.c include/io.h| bin
	gcc $(CFLAGS) -c src/io.c -o bin/io.o
lab1: bin/main.o bin/algorithm.o bin/io.o bin/util.o
	gcc $(CFLAGS) bin/main.o bin/util.o bin/algorithm.o bin/io.o -o lab1