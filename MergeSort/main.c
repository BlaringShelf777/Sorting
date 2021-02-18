
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void mergeSort(int *array, int *aux, int start, int end);
void merge(int *array, int *aux, int start, int end);

int main(){
    int *array = NULL;
    int *aux = NULL;

    array = (int *) malloc(sizeof(int) * SIZE); aux = (int *) malloc(sizeof(int) * SIZE);
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++){
        aux[i] = array[i] = rand() % 101;
    }
    mergeSort(array, aux, 0, SIZE - 1);
    printf("\n\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n\n");
    free(aux); free(array);

    return 0;
}

// Top-Down MergeSort
void mergeSort(int *array, int *aux, int start, int end){
    if (start >= end)
        return;
    
    int mid = start + (end - start)/2;

    mergeSort(array, aux, start, mid);
    mergeSort(array, aux, mid + 1, end);
    merge(array, aux, start, end);
}

// Merge the Array
void merge(int *array, int *aux, int start, int end){
    int mid = start + (end - start)/2;

    if (array[mid] <= array[mid + 1])
        return;
    
    for (int i = start; i <= end; i++)
        aux[i] = array[i];
    for (int k = start, j = mid + 1, i = start; k <= end; k++){
        if (j > end)
            array[k] = aux[i++];
        else if (i > mid)
            array[k] = aux[j++];
        else if (aux[i] <= aux[j])
            array[k] = aux[i++];
        else
            array[k] = aux[j++];
    }
}