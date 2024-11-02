all: aux sortFuncs
	gcc -o main funcAux.o bubble.o insertion.o selection.o main.c -Wall -std=c99

run:
	./main metrics.txt

sortFuncs:
	gcc -c bubble.c insertion.c selection.c -Wall -std=c99

aux:
	gcc -c funcAux.c -Wall -std=c99

clean:
	rm *.o main

