#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 1
#define MAX 5

int *makeArray(int size);
void printArray(int array[], int size);
void selectionSort(int array[], int size);

int main(){
    int *array = makeArray(10);

    printArray(array, 10);
    selectionSort(array, 10);
    printArray(array, 10);

    return 0;
}

// Creates an array of integers of "int size" size
int *makeArray(int size){
    int *array = (int *) malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % (int) pow(10, MIN+(rand() % (MAX - MIN + 1)));
    
    return array;
}

// Prints an array of integers of "int size" size
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf(" %d", array[i]);
    printf("\n");
}

// SelectionSort
void selectionSort(int array[], int size){
    for (int i = 0; i < size; i++){
        int min = i, aux = array[i];

        for (int j = i + 1; j < size; j++)
            if (array[min] > array[j])
                min = j;
        array[i] = array[min];
        array[min] = aux;
    }
}


