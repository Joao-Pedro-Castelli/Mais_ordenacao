#ifndef SORTFUNCTIONS
#define SORTFUNCTIONS

#include <stdbool.h>
#include <time.h>

struct SORTDATA{
    unsigned long int comparisons;
    unsigned long int moves;
    double execTime;
};

struct SORTDATA bubbleSort(int *array, int n);
struct SORTDATA selectionSort(int *array, int n);
struct SORTDATA insertionSort(int *array, int n);
/*
struct SORTDATA shellSort(int *array, int n);
struct SORTDATA quickSort(int *array, int n);
struct SORTDATA heapSort(int *array, int n);
struct SORTDATA mergeSort(int *array, int n);
struct SORTDATA lesserSort(int *array, int n);
struct SORTDATA radixSort(int *array, int n);
*/
bool trocarTem(int *ordem, int a, int b);
void ordemTrocar(int *ordem, int a, int b);
void arrCopiar(int *ordem, int *array, int n);
double microSecondsExecDiff(clock_t end, clock_t begin);

#endif
