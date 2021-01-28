
// library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define ARGS 2

// Function Prototype
int *makeArray(int size);
void printArray(int array[], int size);
void insertionSort(int array[], int size);

int main(int argc, char *argv[]){
    if (argc != ARGS){
        printf("\n> ERROR! usage: <main_file> <array_size>\n\n");
        return 1;
    }

    int size = atoi(argv[argc-1]), *array = makeArray(size);
    
    printArray(array, size);
    printf("-------------SORTED--------------\n");
    insertionSort(array, size);
    printArray(array, size);

    return 0;
}

// Function Implementation:
// Creates an array with random integers up to 100 (not inclusive)
int *makeArray(int size){
    int *array = (int *) malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
    
    return array;
}

// Prints an array of integers of 'int size' length
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf("> %d\n", array[i]);
}

// InsertionSort Algorithm implementation
void insertionSort(int array[], int size){
    for (int i = 1; i < size; i++){
        int j = i - 1, aux = array[i];
        
        while (j >= 0 && aux < array[j]){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = aux;
    }
}



