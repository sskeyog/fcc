G = gcc
D = -lstdc++fs

all:
	$(G) ./src/fcc.c -o fcc $(D)
	rm -rf *.o
