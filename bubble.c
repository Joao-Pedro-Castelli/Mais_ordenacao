#include <stdlib.h>
#include <time.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData bubbleSort(int *array, int n){
	time_t start, end;
	sortData metrics = {0, 0, 0};
	int ordem[n];
	arrCopiar(ordem, array, n);
	start = clock();
	int moves;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1 - i; j++){
			moves = 0;
			if(trocarTem(ordem, j, j + 1)){
				ordemTrocar(ordem, j, j + 1);
				metrics.moves++;
				moves++;
			}
			metrics.comparisons++;
		}
		if(moves == 0){
			break;
		}
	}
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}
