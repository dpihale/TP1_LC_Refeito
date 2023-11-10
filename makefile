all:arquivo.o main.c
	gcc -o main main.c arquivo.o
arquivo.c:arquivo.c
	gcc -c arquivo.c
clean:
	rm *.o *.exe
