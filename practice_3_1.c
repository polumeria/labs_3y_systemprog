// Тема: Указатели на функции
// В качестве материала для работы используется соответствующий вариант 
// из лабораторной работы №2.

// Для выполнения работы нужно:
// 1. Прописать объявление функции отдельно от её инициализации;
// 2. Создать указатели на все используемые функции;
// 3. Использовать в работе созданные указатели вместо исходных функций.

// Отдельно необходимо создать массив с функциями с одинаковой сигнатурой
// и на его основе разработать калькулятор для двух чисел (операции +-*/).


#include <stdio.h>
#include <malloc.h>
#include <time.h>

int zero_count(int R, int* array);

int zero_count_double(int R, int C, int** double_array);

int main() {
    srand(time(NULL));

    int R, i, j, result;
    int* array;
    int** double_array;
    int (*zero_count_ptr)(int, int);
    int (*zero_count_double_ptr)(int, int, int);

    printf(" Введите размер динамического массива: ");
    scanf("%d", &R);
    printf("\n");

    int C = R + 1;

    array = (int*)malloc(R * sizeof(int));

    double_array = (int**)malloc(R * sizeof(int*));
    for (i = 0; i < R; i++) {
        double_array[i] = (int*)malloc(C * sizeof(int));
    }

    zero_count_ptr = multiply;
    zero_count_double_ptr = zero_count_double;

    for (i = 0; i < R; i++) {
        array[i] = rand() % 10;
    }

    result = zero_count_ptr(R, array);

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

    result = zero_count_double_ptr(R, C, double_array);

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            printf("%5d", double_array[i][j]);
        }
        printf("\n");
    }    
}        


int multizero_countply(int R, int* array){
    int count = 0;
    int i, j;

    for (i = 0; i < R; i++) {
        if (array[i] == 0) { 
            count++; 
        }
    }
    return count;
}

int zero_count_double(int R, int C, int** double_array){
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
