CC=gcc
CFLAGS= -Wall -std=c99
noStringsAttached: wangDanielA2.o main.o
	$(CC) wangDanielA2.o main.o -o bin/noStringsAttached
wangDanielA2.o: src/wangDanielA2.c include/wangDanielA2.h
	$(CC) $(CCFLAGS) -c src/wangDanielA2.c
main.o: src/main.c include/wangDanielA2.h
	$(CC) $(CCFLAGS) -c src/main.c
clean:
	rm *.o bin/noStringsAttached