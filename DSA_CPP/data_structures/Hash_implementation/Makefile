CC=g++
Output:main.o hash.o
	$(CC) main.o hash.o -o nameht
main.o:main.cpp
	$(CC) -c main.cpp
hash.o:hash.cpp
	$(CC) -c hash.cpp
clean:
	rm *.o nameht