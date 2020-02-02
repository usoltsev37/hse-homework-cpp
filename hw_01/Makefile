.PHONY: all clean

CFLAGS= -Wall -Wextra -Werror -Wshadow -g -fsanitize=address -fsanitize=undefined -I include

all: hw_01

clean:
	rm -rf obj hw_01

obj:
	mkdir obj

obj/main.o: src/main.c include/bmp.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/bmp.o: src/bmp.c include/bmp.h | obj
	gcc $(CFLAGS) -c src/bmp.c -o obj/bmp.o

hw_01: obj/bmp.o obj/main.o
	gcc $(CFLAGS)  obj/bmp.o obj/main.o -o hw_01