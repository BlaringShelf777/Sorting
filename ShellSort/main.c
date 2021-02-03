#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


int *makeArray(int size);
void printArray(int array[], int size);
void shellSort(int array[], int size, int segments);
void shellSortMain(int array[], int size, int h);


int main(){
    int *array = makeArray(100);

    printf("\n*********\n");
    printArray(array, 100);
    printf("\n*********\n");
    shellSort(array, 100, 4);
    printf("\n\n");

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
}

void shellSort(int array[], int size, int segments){
    for (int i = 1; i <= segments; i++){
        shellSortMain(array, size, (pow(3, segments + 1 - i) - 1) / 2);
        printArray(array, size);
        printf("\n--\n");
    }
}

void shellSortMain(int array[], int size, int h){
    for (int i = h; i < size; i += h){
        int j = i - h, aux = array[i];

        while (j >= 0 && aux < array[j]){
            array[j + h] = array[j];
            j -= h;
        }
        array[j + h] = aux;
    }
}