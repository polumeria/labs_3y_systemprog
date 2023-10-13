// Необходимо продемонстрировать передачу следующих аргументов в функцию:
//
//    обычная переменная, одномерный массив, двумерный массив, указатель
//
// можно переделать предыдущее задание, можно следующее:
// посчитать количество нулей в массиве.
// можно извращать задание так чтобы реализовать все требования

// если мы сделаем динамические массивы, это считается за передачу указателей? да, обязательно *


#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

int zero_count(int R, int array[]){
    int count = 0;
    int i, j;

    for (i = 0; i < R; i++) {
        if (array[i] == 0) { 
            count++; 
        }
    }

    return count;
}

int zero_count_double(int *R, int C, int* double_array[5]){
    int count = 0;
    int i, j;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (double_array[i][j] == 0) { 
                count++; 
            }
        }
    }

    return count;
}

int main() {
    srand(time(NULL));

    int R, i, j, result;
    int* array;
    int** double_array;

    printf(" Введите размер динамического массива: ");
    scanf("%d", &R);
    printf("\n");

    int C = R + 1;

    array = (int*)malloc(R * sizeof(int));

    double_array = (int**)malloc(R * sizeof(int*));
    for (i = 0; i < R; i++) {
        double_array[i] = (int*)malloc(C * sizeof(int));
    }

    for (i = 0; i < R; i++) {
        array[i] = rand() % 10;
    }

    result = zero_count(R, array);

    for (i = 0; i < R; i++) {
        printf("%5d", array[i]);
    }   

    printf("\n Количество нулей в одномерном массиве: %d ", result);
    printf("\n \n");

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            double_array[i][j] = rand() % 10;
        }
    }

    result = zero_count_double(R, C, double_array);

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            printf("%5d", double_array[i][j]);
        }
        printf("\n");
    }   

    printf("\n Количество нулей в двумерном массиве: %d ", result);
    printf("\n \n");

    free(array);
    for (int i = 0; i < R; i++) {
        free(double_array[i]);
    }    
    free(double_array);
    
    return 0;
}
