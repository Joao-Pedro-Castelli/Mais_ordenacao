#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData insertionSort(unsigned int *array, int n){
	clock_t start, end;
	sortData metrics = {0, 0, 0};
	unsigned int ordem[n];
	arrCopiar(ordem, array, n);
	start = clock();
	for(int i = 1; i < n; i++){
		int j;
		unsigned temp = ordem[i];
		for(j = i; j > 0 && trocarTem(ordem, i, j - 1); j--){
			metrics.comparisons++;
			ordem[j] = ordem[j - 1];
			metrics.moves++;
		}
		metrics.comparisons++;
		if(ordem[j] != temp){
			ordem[j] = temp;
			metrics.moves++;
		}
		metrics.comparisons++;
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
