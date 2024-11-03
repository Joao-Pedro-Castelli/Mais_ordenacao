OBJ_CODE := $(wildcard ./sortFiles/*.c)
OBJ_FILES := $(patsubst %.c,%.o,$(OBJ_CODE))

all: sortFuncs $(OBJ_FILES)
	gcc -o main $(OBJ_FILES) main.c -Wall -std=c99

run:
	./main metrics.txt

sortFuncs: $(OBJ_CODE)
	gcc -c $(OBJ_CODE) -Wall -std=c99
	mv -t ./sortFiles *.o

clean:
	rm $(OBJ_FILES) main

