// Лабораторная работа №5
// Работа с многопоточностью при помощи библиотеки pthread.h
// За основу берется лабораторная работа №2 (задания из обоих списков). 
// В процессе выполнения работы необходимо:
// 1. Выделить последовательный код в программе;
// 2. Выделить код, который можно выполнить параллельно;
// 3. Оформить выполнение параллельного кода в виде отдельных потоков.
//
// Полученная программа обязана выполняться максимально эффективно. 
// Для проверки эффективности кода следует увеличить размер массива и замерить 
// время выполнения программы (сравнив с выполнением кода в один поток). В ходе 
// сдачи работы нужно пояснить когда что запускается, где останавливается, где 
// завершается и почему.
//
// При необходимости следует использовать массив с потоками. В ходе сдачи 
// работы нужно пояснить почему выбрано именно указанное число потоков.
//
// При необходимости, можно создавать структуры с аргументами функций, которые 
// нужно запустить в виде отдельных потоков.
//
// Работа ОБЯЗАНА содержать в себе работу с мютексами. В ходе сдачи работы нужно 
// пояснить механику их работы и смысл их существования.
//
// Хотя бы один поток должен возвращать значение, а не работать с глобальными 
// переменными или указателями аргументов функции.
//
// Программа должна содержать механизм прерывания выполнения потока (любого на 
// ваше усмотрение) по команде с клавиатуры.
//
// Докажите, что созданные вами функции для потоков потокобезопасные и реентерабельные.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

pthread_mutex_t my_mutex;

void print_enter(){
    printf(" \n \n");
}

int flag (int a)
{
    if (a == 0) 
    {
        return true;
    }
    else  return false;
}

int zero_count(int R, int* array){
    int count = 0;
    int i;

    for (i = 0; i < R; i++) {
        if (flag(array[i])){
            count++;
        }
    }
    return count;
}

int zero_count_double(int rows, int columns, int** array){
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

void* array_zeros(void* args){
    srand(time(NULL));

    int R = 15;
    int* array;
    array = (int*)malloc(R * sizeof(int));

    pthread_mutex_lock(&my_mutex);
    for (int i = 0; i < R; i++) {
        array[i] = rand() % 10;
    }

    printf("массив из потока 1");
    print_enter();
    for (int i = 0; i < R; i++) {
        printf("%5d", array[i]);
    } 

    int result = zero_count(R, array);
    pthread_mutex_unlock(&my_mutex);
    print_enter();
    printf("Количество нулей в одномерном массиве: %d", result);
    print_enter();

    free(array);
}

void* double_array_zeros(void* args){
    srand(time(NULL));

    int R = 6;
    int C = R + 1;
    int** array;
    array = (int**)malloc(R * sizeof(int*));
    for (int i = 0; i < R; i++) {
        array[i] = (int*)malloc(C * sizeof(int));
    }
    
    pthread_mutex_lock(&my_mutex);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            array[i][j] = rand() % 10;
        }
    }

    printf("массив из потока 2");
    print_enter();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }   
    
    int result = zero_count_double(R, C, array);

    pthread_mutex_unlock(&my_mutex);
    print_enter();
    printf("Количество нулей в двумерном массиве: %d", result);
    print_enter();

    for (int i = 0; i < R; i++) {
        free(array[i]);
    }    
    free(array);
}

int main() 
{
    pthread_t my_thread;

    pthread_create(&my_thread, NULL, array_zeros, NULL);
    pthread_join(my_thread, NULL);

    pthread_create(&my_thread, NULL, double_array_zeros, NULL);
    pthread_join(my_thread, NULL);
    return 0;
}
