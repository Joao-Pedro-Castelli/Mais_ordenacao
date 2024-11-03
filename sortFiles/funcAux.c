#include "sortFunctions.h"

bool trocarTem(unsigned int *ordem, int a, int b){
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

void ordemTrocar(unsigned int *ordem, int a, int b){
	unsigned int temp = ordem[a];
	ordem[a] = ordem[b];
	ordem[b] = temp;
	return;
}

void arrCopiar(unsigned int *ordem, unsigned int *array, int n){
	for(int i = 0; i < n; i++){
		ordem[i] = array[i];
	}
	return;
}

double microSecondsExecDiff(clock_t end, clock_t begin){
	return (end - begin) * 1000000 / CLOCKS_PER_SEC;
}
