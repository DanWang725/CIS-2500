wangDanielA1: wangDanielA1.o main.o
	gcc -Wall -std=c99 wangDanielA1.o main.o -o wangDanielA1
wangDanielA1.o: wangDanielA1.c wangDanielA1.h
	gcc -Wall -std=c99 -c wangDanielA1.c
main.o: main.c wangDanielA1.h
	gcc -Wall -std=c99 -c main.c
clean:
	rm *.o wangDanielA1