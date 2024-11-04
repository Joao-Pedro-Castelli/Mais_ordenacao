#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData quickRecursive(unsigned int *ordem, int inicio, int fim);
int pivoEscolher(unsigned int *ordem, int meio, int tam, sortData *metricsptr);

sortData quickSort(unsigned int *array, int n){
	clock_t start, end;
	unsigned int ordem[n];
	arrCopiar(ordem, array, n);
	sortData metrics = {0, 0, 0};
	start = clock();
	metrics = quickRecursive(ordem, 0, n -1);
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}

sortData quickRecursive(unsigned int *ordem, int inicio, int fim){
	sortData metrics = {0, 0, 0};
	if(fim - inicio <= 0){ //fim - inicio == numero de elementos naquele subvetor menos um
		metrics.comparisons++;
		return metrics;
	}
	if(fim - inicio == 1){
		metrics.comparisons++;
		if(trocarTem(ordem, inicio, fim)){
			ordemTrocar(ordem, inicio, fim);
			metrics.moves++;
		}
		metrics.comparisons++;
		return metrics;
	}
	int meio = (inicio + fim) / 2;
	int pivo = pivoEscolher(ordem, meio, fim - inicio, &metrics);
	int i = inicio;
	int j = fim;
	while(true){
		while(!trocarTem(ordem, i, pivo)){ //caso i e o pivo sejam iguais, trocarTem retornara falso
			metrics.comparisons++;
			if(i == pivo){
				metrics.comparisons++;
				break;
			}
			i++;
		}
		while(!trocarTem(ordem, pivo, j)){
			metrics.comparisons++;
			if(j == pivo){
				metrics.comparisons++;
				break;
			}
			j--;
		}
		if(i >= j){
			metrics.comparisons++;
			break;
		}
		ordemTrocar(ordem, i, j);
		metrics.moves++;
		if(i == pivo){
			metrics.comparisons++;
			pivo = j;
		}
		else if(j == pivo){
			pivo = i;
		}
	}
	sortData tmp = quickRecursive(ordem, inicio, pivo - 1);
	metrics = sortdataSum(metrics, tmp);
	if(pivo != fim){
		metrics.comparisons++;
		sortData tmp = quickRecursive(ordem, pivo + 1, fim);
		metrics = sortdataSum(metrics, tmp);
	}
	return metrics;
}

int pivoEscolher(unsigned int *ordem, int meio, int tam, sortData *metricsptr){
	if(tam > 4){
		if(trocarTem(ordem, meio, meio + 1)){
			if(trocarTem(ordem, meio - 1, meio + 1)){
				metricsptr->comparisons += 3;
				return meio - 1;
			}
			else{
				metricsptr->comparisons += 3;
				return meio + 1;
			}
		}
		else{
			if(trocarTem(ordem, meio - 1, meio)){
				metricsptr->comparisons += 3;
				return meio - 1;
			}
			else{
				metricsptr->comparisons += 3;
				return meio;
			}
		}
	}
	else{
		metricsptr->comparisons++;
		return meio;
	}
}

