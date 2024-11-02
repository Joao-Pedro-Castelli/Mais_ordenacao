#include <stdio.h>
#include <stdlib.h>
#include "sortFunctions.h"

#define ARRAY_SIZE 100000
typedef struct SORTDATA sortData;

//this function puts the ARRAY_SIZE numbers in the file on the array
void readFile(int *array, char *fileNames);

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("escreva o nome do arquivo de destino da gravacao no comando de execucao\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "w");
	//array of pointers to functions, the functions are defined in the header
	sortData (*sortingFunctions[])(int *, int) = {&bubbleSort, &selectionSort, &insertionSort};// &shellSort, &quickSort, &heapSort, &mergeSort, &lesserSort, &radixSort};
	char *functionNames[] = {"Bubble sort", "Selection sort", "Insertion sort"}; //, "Shell sort", "Quick sort", "Heap sort", "Merge sort", "Lesser sort", "Radix sort"};
	//array to string of the files that contain the number to be sorted
	char *fileNames[] = {"random0.txt", "random1.txt", "random2.txt", "random3.txt", "random4.txt", "ordenado.txt", "inordenado.txt"};
	//array to be sorted
	int array[ARRAY_SIZE];
	//sortData is a struct that contains three ints
	sortData metrics = {0, 0, 0};
	//pointer to function, will be used to iterate over the function pointers on the array
	sortData (*sortFunc)(int *, int);
	for(int i = 0; i < 3; i++){
		sortFunc = sortingFunctions[i];
		fprintf(fp, "\n\n\nFunction %s:\n", functionNames[i]);
		for(int j = 0; j < 7; j++){
			readFile(array, fileNames[j]);
			fprintf(fp, "\n\nFor file %s:\n", fileNames[j]);
			for(int w = 100; w <= ARRAY_SIZE; w *= 10){
				fprintf(fp, "\nFor %d size:\n", w);
				metrics = sortFunc(array, w);
				fprintf(fp, "%lu <- Number of comparisons\n%lu <- Number of register movements\n%lfusec <- Execution time\n", metrics.comparisons, metrics.moves, metrics.execTime);
			}
		}
	}
	return 0;
}

void readFile(int *array, char *fileName){
	FILE *fp = fopen(fileName, "r");
	fseek(fp, 0, SEEK_SET);
	int num = 0;
	int c;
	for(int i = 0; i != ARRAY_SIZE; i++){
		while((c = fgetc(fp)) != '\n'){
			num *= 10; //simple arithmetic, i read a new digit of the number, do a decimal shift left and add the digit
			num += c;
		}
		array[i] = num;
		num = 0;
	}
	fclose(fp);
	return;
}
