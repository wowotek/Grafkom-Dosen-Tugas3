CC=g++
CARGS=-W -Wall -Werror -Wextra -Wpedantic -g -O3

bin/main: bin/obj/main.o
	$(CC) $(CARGS) -o main main.o

bin/obj/main.o:	src/source/main.cpp src/header/wo2glib.hpp src/header/wo2util.hpp
	$(CC) $(CARGS) -o main.o -c main.cpp

clean:
	rm -rf prog1 main.o