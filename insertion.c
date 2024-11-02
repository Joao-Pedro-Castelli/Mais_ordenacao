#include <stdlib.h>
#include <time.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData insertionSort(int *array, int n){
	time_t start, end;
	sortData metrics = {0, 0, 0};
	int ordem[n];
	arrCopiar(ordem, array, n);
	start = clock();
	for(int i = 1; i < n; i++){
		int j, temp;
		temp = ordem[i];
		for(j = i; j > 0 && trocarTem(ordem, i, j - 1); j--){
			metrics.comparisons++;
			ordem[j] = ordem[j - 1];
			metrics.moves++;
		}
		metrics.comparisons++;
		ordem[j] = temp;
		metrics.moves++;
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
