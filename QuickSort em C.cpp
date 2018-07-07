#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

struct timespec timer_start();

long timer_end(struct timespec start_time);

int main() {
	int *item, tam, i;
	struct timespec initialTime;
	long time_elapsed_nanos;
	
	printf("Insira o numero de itens do vetor: ");
	scanf("%d", &tam);
	
	fflush(stdin);
	item = (int*) malloc (tam * sizeof(int));
	
	for (i=0; i < tam; i++){
		printf("Insira o valor da posicao %d do vetor: ", i+1);
		scanf("%d", &item[i]);
		fflush(stdin);
	}

	
	printf("\n\nO vetor desordenado e: ");
	for(i=0; i<tam; i++){
		printf(" %d |", item[i]);
	}

	initialTime = timer_start(); 
	
	quick_sort(item, 0, tam-1);
	
	time_elapsed_nanos = timer_end(initialTime);
	
	
	printf("\n\nO vetor ordenado e: ");
	for(i=0; i<tam; i++){
		printf(" %d |", item[i]);
	}
	
	
	printf("\n\nO tempo gasto para ordenacao e: %ld\n", time_elapsed_nanos);
	return 0;
}


struct timespec timer_start(){
    struct timespec start_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    return start_time;
}

long timer_end(struct timespec start_time){
    struct timespec end_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
    long diffInNanos = end_time.tv_nsec - start_time.tv_nsec;
    return diffInNanos;
}
