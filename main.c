// Лабораторная работа №6
// Тема работы: Макросы
// За основу берется лабораторная работа №2.
// 1. Использовать макросы для подключения кода из других файлов;   +
// 2. Представить уникальный пример использования макроса без параметров;   
// 3. Оформить одну из функций в виде макроса с параметрами;    +
// 4. (Дополнительно) Привести пример перегрузки функций.   

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"

#define amount(size) (size + 1)
#define print_result(count) (printf("количество нулей в массиве: %d", count))


void print_enter(){
    printf(" \n \n");
}

int main(){
 srand(time(NULL));

    int size, i;
    int* array;
    int** double_array;

    print_enter();
    printf("Введите размер динамического массива: ");
    scanf("%d", &size);
    printf("\n");

    array = (int*)malloc(size * sizeof(int));

    double_array = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++) {
        double_array[i] = (int*)malloc(amount(size) * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        array[i] = rand() % 10;
    }

    print_array(array, size);
    print_enter();

    print_result(zero_count(array, size));
    print_enter();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < amount(size); j++) {
            double_array[i][j] = rand() % 10;
        }
    }

    print_matrix(double_array, size, amount(size));
    print_enter();

    print_result(zero_count_double(double_array, size, amount(size)));
    print_enter();

    free(array);
    for (int i = 0; i < size; i++) {
        free(double_array[i]);
    }    
    free(double_array);

    return 0;
}
