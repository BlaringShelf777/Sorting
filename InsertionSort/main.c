
// library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function Prototype
void makeArray(int array[], int size);
void printArray(int array[], int size);
void insertionSort(int array[], int size);

int main(){
    int array[SIZE] = {0};
    
    makeArray(array, SIZE);
    printArray(array, SIZE);
    printf("-------------SORTED--------------\n");
    insertionSort(array, SIZE);
    printArray(array, SIZE);

    return 0;
}

// Function Implementation:
// Creates an array with random integers up to 100 (not inclusive)
void makeArray(int array[], int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
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



