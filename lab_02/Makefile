.PHONY: all clean

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I include

all: lab_02

clean:
	rm -rf obj lab_02
obj:
	mkdir obj
obj/test.o: src/test.c include/str.h include/test_str.h | obj
	gcc $(CFLAGS) -c src/test.c -o obj/test.o
obj/str.o: src/str.c include/str.h | obj
	gcc $(CFLAGS) -c src/str.c -o obj/str.o
obj/test_str.o: src/test_str.c include/str.h include/test_str.h | obj
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o
lab_02: obj/test.o obj/str.o obj/test_str.o
	gcc $(CFLAGS) obj/test.o obj/str.o obj/test_str.o -o lab_02