all: bsort.c bsort.h ssort.c ssort.h isort.c isort.h main.c
	gcc bsort.c bsort.h ssort.c ssort.h isort.c isort.h main.c -o main
	./main


