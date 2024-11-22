#include <stdlib.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData radix_sort(unsigned int *v, int tamanho);
sortData couting_sort(unsigned int *v, int tamanho, int po);

sortData radixSort(unsigned int *array, int n){
    clock_t start, end;
    unsigned int ordem[n];
    arrCopiar(ordem, array, n);
    sortData metrics = {0, 0, 0};
    start = clock();
    metrics = radix_sort(ordem, n);
    end = clock();
    metrics.execTime = microSecondsExecDiff(end, start);
    return metrics;
}

sortData radix_sort(unsigned int *v, int tamanho){
    int maior = v[0];
    sortData metrics = {0, 0, 0};
    for(int i=0;i<tamanho;i++){
        if(maior<v[i]){
            maior = v[i];

        }
	metrics.comparisons++;
    }

    
    for(int i=1;maior/i>=1;i*=10){
        sortData datatmp = couting_sort(v,tamanho,i);
	metrics = sortdataSum(metrics, datatmp);

   }
   return metrics;

}

sortData couting_sort(unsigned int *v, int tamanho, int pot){
    sortData metrics = {0, 0, 0};
    unsigned int aux[10];

    unsigned int saida[tamanho];

    for(int i=0;i<10;i++){
        aux[i] = 0;
	metrics.moves++;
    }

    for (int i = 0; i < tamanho; i++){
        aux[(v[i]/pot)%10]++;
	metrics.moves++;
    }

    for(int i =1; i< 10; i++){
        aux[i] += aux[i-1];
	metrics.moves++;
    }

   for(int i=tamanho-1;i>=0;i--){

    saida[aux[(v[i]/pot)%10]-1] = v[i];
    aux[(v[i]/pot)%10]--;
    metrics.moves += 2;
        
    }

    for(int i=0;i<tamanho;i++){
        v[i] = saida[i];
	metrics.moves++;
    }
    return metrics;
}

