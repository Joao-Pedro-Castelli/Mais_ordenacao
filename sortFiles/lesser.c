#include <stdlib.h>
#include "sortFunctions.h"

typedef struct SORTDATA sortData;

sortData contagem_menores(int tamanho, unsigned int*v);

sortData lesserSort(unsigned int *array, int n){
    clock_t start, end;
    sortData metrics = {0, 0, 0};
    unsigned int ordem[n];
    arrCopiar(ordem, array, n);
    start = clock();
    metrics = contagem_menores(n, ordem);
    end = clock();
    metrics.execTime = microSecondsExecDiff(end, start);
    return metrics;
}

sortData contagem_menores(int tamanho, unsigned int*v){
    

    sortData metrics = {0, 0, 0};
    int aux1[tamanho];

    int aux2[tamanho];
    for(int i = 0;i<tamanho;i++){
        aux1[i] = 0;
        aux2[i] = 0;
	metrics.moves += 2;

    }

    for(int i=0;i<tamanho;i++){
        for(int j=i+1;j<tamanho;j++){
            if(v[i]>v[j]){
                aux1[i]++;
            }
            else if(v[i]==v[j]){
		metrics.comparisons++;
                aux1[i]++;
            }
            else{
		metrics.comparisons++;
                aux1[j]++;
            }
	    metrics.moves++;
            metrics.comparisons++;
        }
    }
    


    for(int i=0;i<tamanho;i++){
        
        aux2[aux1[i]] = v[i];
        metrics.moves++;

        
    }
    
    for(int i=0;i<tamanho;i++){
        v[i] = aux2[i];
        metrics.moves++;
    }

    return metrics;

}
