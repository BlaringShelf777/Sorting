
#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

void mergeSort(int *array, int *aux, int start, int end);
void merge(int *array, int *aux, int start, int end);

int main(){
    int array[] = {10, 8, 22, 2, 11, 10, 1, 0, 100, 1, 13};
    int *aux = NULL;

    aux = (int *) malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        aux[i] = array[i];
    mergeSort(array, aux, 0, SIZE - 1);
    free(aux);
    printf("\n\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n\n");

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