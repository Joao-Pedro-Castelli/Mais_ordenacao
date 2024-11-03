#include "sortFunctions.h"

#define SEQUENCE_LEN 8
typedef struct SORTDATA sortData;

sortData shellSort(unsigned int *array, int n){
	clock_t end, start;
	unsigned int ordem[n];
	arrCopiar(ordem, array, n);
	sortData metrics = {0, 0, 0};
	start = clock();
	//a sequence for shell sort found on wikipedia that seems good for arrays with more than 1000 elements
	int gapArr[] = {1, 4, 10, 23, 57, 132, 301, 701};
	int i = SEQUENCE_LEN - 1;
	while(gapArr[i] > n){
		i--;
	}
	for(int gap = gapArr[i]; i >= 0; --i){
		gap = gapArr[i];
		unsigned int aux;
		for(int j1 = gap; j1 < n; j1++){
			aux = ordem[j1];
			int j2;
			for(j2 = j1; (j2 > gap - 1) && (ordem[j2 - gap] > aux); j2 -= gap){
				metrics.comparisons++;
				ordem[j2] = ordem[j2 - gap];
				metrics.moves++;
			}
			metrics.comparisons++;
			if(ordem[j2] != aux){
				ordem[j2] = aux;
				metrics.moves++;
			}
			metrics.comparisons++;
		}
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
