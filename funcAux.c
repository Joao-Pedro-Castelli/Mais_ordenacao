#include "sortFunctions.h"

bool trocarTem(int *ordem, int a, int b){
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(ordem[a] > ordem[b]){
		return true;
	}
	return false;
}

void ordemTrocar(int *ordem, int a, int b){
	int temp = ordem[a];
	ordem[a] = ordem[b];
	ordem[b] = temp;
	return;
}

void arrCopiar(int *ordem, int *array, int n){
	for(int i = 0; i < n; i++){
		ordem[i] = array[i];
	}
	return;
}

double microSecondsExecDiff(clock_t end, clock_t begin){
	return (end - begin) * 1000000 / CLOCKS_PER_SEC;
}
