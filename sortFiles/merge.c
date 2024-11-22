#include <stdlib.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData merge_sort_aux(unsigned int* v,int ini, int fim, int meio);
sortData merge_sort(unsigned int *v, int ini, int fim, int meio);

int max(int a, int b){
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

sortData mergeSort(unsigned int *array, int n){
	clock_t start, end;
	unsigned int ordem[n];
	arrCopiar(ordem, array, n);
	sortData metrics = {0, 0, 0};
	start = clock();
	metrics = merge_sort(ordem, 0, n - 1, (n - 1)/2);
	end = clock();
	metrics.execTime = microSecondsExecDiff(end, start);
	return metrics;
}

sortData merge_sort(unsigned int *v, int ini, int fim, int meio){
    sortData metrics = merge_sort_aux(v,0,fim, meio);
    return metrics;
}


sortData merge_sort_aux(unsigned int* v,int ini, int fim, int meio){
    sortData metrics = {0, 0, 0};
    if(ini == fim){
	metrics.comparisons++;
        return metrics;
    }

    //Calculando tamanho dos vetores auxiliares. Cada um receberá metade dos valores do vetor original
    int n1,n2;
    n1= meio - ini+1;
    n2 = fim - meio;


   sortData datatmp = metrics;

    datatmp = merge_sort_aux(v,ini,meio,(meio+ini)/2);
    metrics = sortdataSum(metrics, datatmp);
    datatmp = merge_sort_aux(v,meio+1,fim,(meio+fim+1)/2);
    metrics = sortdataSum(metrics, datatmp);

    int e[n1], d[n2];

    for(int i=0;i<n1;i++){
        e[i] = v[ini+i];
	metrics.moves++;
    }

    for(int i=0;i<n2;i++){
        d[i] = v[meio+1+i];
	metrics.moves++;
    }

    int i=0,j=0;
    int k = ini;

    while(i<n1 && j<n2){
        metrics.comparisons++;
        if(e[i]<=d[j]){
            v[k] = e[i];
            k++;
            i++;
        }
        else{
            v[k] = d[j];
            k++;
            j++;
        }
	metrics.moves++;
	metrics.comparisons++;
    }
    metrics.comparisons++;

    while(i<n1){
    	metrics.comparisons++;
        v[k] = e[i];
	metrics.moves++;
        k++;
        i++;
    }
    metrics.comparisons++;

    while(j<n2){
    	metrics.comparisons++;
        v[k] = d[j];
	metrics.moves++;
        k++;
        j++;

    }
    metrics.comparisons++;
    return metrics;

}

