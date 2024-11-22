#include <stdlib.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData heapAux(unsigned int *ordem, int n);
sortData heapRefazer(unsigned int *ordem, int tamHeap, int inicio);
sortData heapConstruir(unsigned int *ordem, int n, int inicio);

sortData heapSort(unsigned int *array, int n){
	clock_t start, end;
	sortData metrics = {0, 0, 0};
	unsigned int ordem[n];
	arrCopiar(ordem, array, n);
	start = clock();
	metrics = heapAux(ordem, n);
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}

sortData heapAux(unsigned int *ordem, int n){
	sortData metrics = heapConstruir(ordem, n, 0);
	sortData temp = {0, 0, 0};
	for(int i = 0; i < n - 1; i++){
		ordemTrocar(ordem, 0, n - 1 - i);
		temp = heapRefazer(ordem, n - i - 1, 0);
		metrics = sortdataSum(metrics, temp);
	}
	return metrics;
}

sortData heapRefazer(unsigned int *ordem, int tamHeap, int inicio){
	sortData metrics = {0, 0, 0};
	sortData temp = metrics;
	if((inicio * 2) + 2 < tamHeap){
		metrics.comparisons++;
		if(trocarTem(ordem, inicio, (inicio * 2) + 1) || trocarTem(ordem, inicio, (inicio * 2) + 2)){
			if(trocarTem(ordem, (inicio * 2) + 1, (inicio * 2) + 2)){
				ordemTrocar(ordem, inicio, (inicio * 2) + 2);
				temp = heapRefazer(ordem, tamHeap, (inicio * 2) + 2);
			}else{
				ordemTrocar(ordem, inicio, (inicio * 2) + 1);
				temp = heapRefazer(ordem, tamHeap, (inicio * 2) + 1);
			}
			metrics.moves++;
			metrics = sortdataSum(metrics, temp);
			metrics.comparisons++;
		}
		metrics.comparisons++;
	}
	else if((inicio * 2) + 1 < tamHeap){
		metrics.comparisons += 2;
		if(trocarTem(ordem, inicio, (inicio * 2) + 1)){
			ordemTrocar(ordem, inicio, (inicio * 2) + 1);
			metrics.moves++;
			temp = heapRefazer(ordem, tamHeap, (inicio * 2) + 1);
			metrics = sortdataSum(metrics, temp);
		}
		metrics.comparisons++;
	}
	metrics.comparisons += 2;
	return metrics;
}

sortData heapConstruir(unsigned int *ordem, int n, int inicio){
	int noAtual = inicio;
	sortData metrics = {0, 0, 0};
	sortData temp = metrics;
	if((inicio * 2) + 2 < n){
		metrics.comparisons++;
		temp = heapConstruir(ordem, n, (inicio * 2) + 1);
		metrics = sortdataSum(metrics, temp);
		temp = heapConstruir(ordem, n, (inicio * 2) + 2);
		metrics = sortdataSum(metrics, temp);
		while((noAtual * 2 + 1 < n) && (trocarTem(ordem, (noAtual * 2) + 1, noAtual) || trocarTem(ordem, (noAtual * 2) + 2, noAtual))){
			metrics.comparisons += 2;
			if(trocarTem(ordem, (noAtual * 2) + 1, (noAtual * 2) + 2)){
					ordemTrocar(ordem, noAtual, (noAtual * 2) + 2);
					noAtual = (noAtual * 2) + 2;
			}
			else{
				ordemTrocar(ordem, noAtual, (noAtual * 2) + 1);
				noAtual = (noAtual * 2) + 1;
			}
			metrics.comparisons++;
			metrics.moves++;
		}
		metrics.comparisons++;
	}
	else if((inicio * 2) + 1 < n){
		metrics.comparisons += 2; //this is for the last if and else
		temp = heapConstruir(ordem, n, (inicio * 2) + 1);
		metrics = sortdataSum(metrics, temp);
		while((noAtual * 2 + 1 < n) && (trocarTem(ordem, (noAtual * 2) + 1, noAtual))){
			metrics.comparisons += 2;
			ordemTrocar(ordem, (noAtual * 2) + 1, noAtual);
			metrics.moves++;
			noAtual = (noAtual * 2) + 1;
		}
	}
	return metrics;
}
