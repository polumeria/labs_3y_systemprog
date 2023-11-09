#include "init.h"
#include <stdio.h>
#include <stdbool.h>

int flag (int a){
    if (a == 0) {
        return true;
    }
    else return false;
}

int zero_count(int* array, int size){
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (flag(array[i])){
            count++;
        }
    }
    return count;
}

int zero_count_double(int** array, int rows, int columns){
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (flag(array[i][j])) { 
                count++; 
            }
        }
    }
    return count;
}

void print_array(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%5d", array[i]);
    }   
}

void print_matrix(int** array, int rows, int columns){
for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }   
}
