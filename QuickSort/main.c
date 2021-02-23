#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 0
#define MIN 2
#define SIZE 8

// QuickSort
void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);
// Random Array
int *makeArray(int size);
void printArray(int array[], int size);

int main(){
    int *array = makeArray(SIZE);

    printArray(array, SIZE);
    quickSort(array, 0, SIZE - 1);
    printArray(array, SIZE);

    return 0;
}

// QuickSort
void quickSort(int *array, int start, int end){
    if (start >= end)
        return;
    
    int pivot = partition(array, start, end);

    quickSort(array, start, pivot-1);
    quickSort(array, pivot+1, end);
}

// Partition using the Hoare Method
int partition(int *array, int start, int end){
    int pivotVal = array[start];
    int i = start, j = end, left = 1;

    while (i != j){
        if (left){
            if (array[j] > pivotVal)
                j--;
            else{
                left = 0;
                array[i++] = array[j];
            }
        }else{
            if(array[i] <= pivotVal)
                i++;
            else{
                left = 1;
                array[j--] = array[i];
            }
        }
    }
    array[j] = pivotVal;

    return j;
}

// Creates an Array
int *makeArray(int size){
    int *array = (int *) malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % (int) pow(10, MIN+(rand() % (MAX - MIN + 1)));
    
    return array;
}

// Prints the Array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
