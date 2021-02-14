#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 1
#define MAX 1
#define SIZE 7

// HeapSort
void buildHeap(int array[], int size);
void heapify(int array[], int size, int index);
// Array
int *makeArray(int size);
void printHeap(int array[], int size);

int main(){
    int *array = makeArray(SIZE);

    printHeap(array, SIZE);
    buildHeap(array, SIZE);
    printf("\n\n");
    printHeap(array, SIZE);

    return 0;
}

// Creates a Heap
void buildHeap(int array[], int size){
    for (int i = size - 1; i > 0; i--)
        heapify(array, size, i/2);
}

// Adjusts the Heap
void heapify(int array[], int size, int index){
    int aux = array[index];
    
    if ((index + 1) * 2 < size && array[(index + 1) * 2] > array[index]){
        if (array[(index + 1) * 2] > array[(index + 1) * 2 - 1]){
            array[index] = array[(index + 1) * 2];
            array[(index + 1) * 2] = aux;
            heapify(array, size, (index + 1) * 2);
        }else{
            array[index] = array[(index + 1) * 2 - 1];
            array[(index + 1) * 2 - 1] = aux;
            heapify(array, size, (index + 1) * 2 - 1);
        }
    }else if((index + 1) * 2 - 1 < size && array[(index + 1) * 2 - 1] > array[index]){
        array[index] = array[(index + 1) * 2 - 1];
        array[(index + 1) * 2 - 1] = aux;
        heapify(array, size, (index + 1) * 2 - 1);
    }
}

// Creates an Array
int *makeArray(int size){
    int *array = (int *) malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % (int) pow(10, MIN+(rand() % (MAX - MIN + 1)));
    
    return array;
}

// Prints the Heap
void printHeap(int array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
        switch (i + 1){
            case 1:
            case 3:
            case 7:
            case 15:
                printf("\n");
            break;
        
            default:
            break;
        }
    }
    printf("\n");
}


