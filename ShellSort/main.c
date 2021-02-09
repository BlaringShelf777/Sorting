#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define ARGS 2

int *makeArray(int size);
void printArray(int array[], int size);
void shellSort(int array[], int size);

int main(int argc, char *argv[]){
    if (argc != ARGS){
        printf("\n> ERROR! usage: <main_file> <array_size>\n\n");
        return 1;
    }

    int size = atoi(argv[argc-1]), *array = makeArray(size);
    printf("\n----------INPUT ARRAY------------\n");
    printArray(array, size);
    printf("\n-------------SORTED--------------\n");
    shellSort(array, size);
    printf("\n");

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
        printf(" %d", array[i]);
    printf("\n");
}

void shellSort(int array[], int size){
    int segment = 0, pot = 1;

    while((int) floor(size / pow(2, pot))){
        segment = (int) floor(size / pow(2, pot++));
        for (int i = 0; i < size; i++)
            for (int j = segment + i; j < size; j += segment){
                int k = j - segment, aux = array[j];

                while (k >= 0 && aux < array[k]){
                    array[k + segment] = array[k];
                    k -= segment;
                }
                array[k + segment] = aux;
            }
        printf("After increments of size %d the list is: ", segment);
        printArray(array, size);
    }
}  
  