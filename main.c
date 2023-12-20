// Лабораторная работа №8
// Работа с бинарными файлами
// Оформить соответствующие варианты для 2 лабораторной работы так, 
// чтобы исходные данные брались из бинарного файла input.bin, а ответ 
// выводился в бинарный файл output.bin

#include <stdio.h>
#include <stdbool.h>

int flag (int a){
    if (a == 0) {
        return true;
    }
    else  return false;
}

int zero_count(int R, int array[]){
    int count = 0;
    int i;

    for (i = 0; i < R; i++) {
        if (flag(array[i])){
            count++;
        }
    }
    return count;
}

int main()
{
    int i, j, result;
    int buff;
    int R = 42;

    int array[42] = {0,    1,    7,    6,    0,    2,    5,
    8,    8,    5,    9,    1,    6,    3,
    7,    0,    4,    4,    8,    4,    7,
    3,    0,    6,    9,    2,    4,    0,
    7,    7,    9,    7,    9,    6,    3,
    1,    0,    1,    1,    8,    8,    2};

    FILE* input;
    input = fopen("../input.bin", "wb+");
    fwrite(&array, sizeof(int), R, input);
    fclose(input);

    input = fopen("../input.bin", "rb");
    fread(&array, sizeof(int), R, input);
    fclose(input);

    result = zero_count(R, array);

    FILE *output;
    output = fopen("output.bin", "wb+");
    fwrite(&result, sizeof(int), 1, output);
    fclose(output);

    output = fopen("output.bin", "rb");
    fread(&buff, sizeof(int), 1, input);
    fclose(output);

    printf("%d", buff);

    return 0;
}
