#ifndef SORTFUNCTIONS
#define SORTFUNCTIONS

#include <stdbool.h>
#include <time.h>

struct SORTDATA{
    unsigned long int comparisons;
    unsigned long int moves;
    double execTime;
};

struct SORTDATA bubbleSort(unsigned int *array, int n);
struct SORTDATA selectionSort(unsigned int *array, int n);
struct SORTDATA insertionSort(unsigned int *array, int n);
struct SORTDATA shellSort(unsigned int *array, int n);
struct SORTDATA quickSort(unsigned int *array, int n);
struct SORTDATA heapSort(unsigned int *array, int n);
/*
struct SORTDATA mergeSort(unsigned int *array, int n);
struct SORTDATA lesserSort(unsigned int *array, int n);
struct SORTDATA radixSort(unsigned int *array, int n);
*/
bool trocarTem(unsigned int *ordem, int a, int b);
void ordemTrocar(unsigned int *ordem, int a, int b);
void arrCopiar(unsigned int *ordem, unsigned int *array, int n);
double microSecondsExecDiff(clock_t end, clock_t begin);
struct SORTDATA sortdataSum(struct SORTDATA metrics, struct SORTDATA tmp);

#endif
