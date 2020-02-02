.PHONY: all clean

CFLAGS= -Wall -Wextra -Werror -Wshadow -g -fsanitize=address -fsanitize=undefined -I include -std=c99

all: lab_05

clean:
	rm -rf obj lab_05

obj:
	mkdir obj

obj/clist.o: src/clist.c include/clist.h | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj/main.o: src/main.c include/point_list.h include/clist.h | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/point_list.o: src/point_list.c include/point_list.h include/clist.h | obj
	gcc $(CFLAGS) -c src/point_list.c -o obj/point_list.o

lab_05: obj/clist.o obj/main.o obj/point_list.o
	gcc $(CFLAGS)  obj/clist.o obj/point_list.o obj/main.o -o lab_05