#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData bubbleSort(int *array, int n){
	time_t start, end;
	sortData metrics = {0, 0, 0};
	int *ordem = (int *) malloc(sizeof(int) * n);
	arraCopiar(ordem, array, n);
	start = clock();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(trocarTem(j, j + 1, ordem)){
				trocarOrdem(j, j + 1, ordem);
				metrics.moves++;
			}
			metrics.comparisons++;
		}
	}
	end = clock();
	metrics.execTime = difftime(end, start);
	free(ordem);
	return metrics
}
