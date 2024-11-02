#include <stdlib.h>
#include <time.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData selectionSort(int *array, int n){
	time_t start, end;
	int ordem[n];
	arrCopiar(ordem, array, n);
	sortData metrics = {0, 0, 0};
	start = clock();
	for(int i = 0; i < n - 1; i++){
		int menorPos = i;
		for(int j = i + 1; j < n; j++){
			if(trocarTem(ordem, menorPos, j)){
				menorPos = j;
			}
			metrics.comparisons++;
		}
		ordem[i] = ordem[menorPos];
		metrics.moves++;
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
