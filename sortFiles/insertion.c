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
		for(j = i - 1; j >= 0 && ordem[j] > temp; j--){
			metrics.comparisons++;
			ordem[j + 1] = ordem[j];
			metrics.moves++;
		}
		metrics.comparisons++;
		ordem[j + 1] = temp;
		metrics.moves++;
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
