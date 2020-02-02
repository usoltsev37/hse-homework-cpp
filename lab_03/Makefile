.PHONY: all clean
	CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address -v -I include

all: lab_03

clean:
	rm -rf obj lab_03

obj:
	mkdir obj

obj/clist.o: src/clist.c | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj/main.o: src/main.c | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

lab_03: obj/clist.o obj/main.o
	gcc $(CFLAGS)  obj/clist.o obj/main.o -o lab_03