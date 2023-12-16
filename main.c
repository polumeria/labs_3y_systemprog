// Лабораторная работа №7
// Работа с текстовыми файлами
// Оформить соответствующие варианты для 2 лабораторной работы 
// так, чтобы исходные данные брались из текстового файла input.txt, 
// а ответ выводился в текстовый файл output.txt

#include <stdio.h>
#include <malloc.h>
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
    int R = 42 + 1;
    int* array;
    array = (int*)malloc(R * sizeof(int));


    FILE* input;
    // input = fopen("../input.txt", "r");
    if ((input = fopen("input.txt", "r")) == NULL){
       printf("file does not exist");
       exit(1);
    }

    for (i = 0; i < R; i++) {
        fscanf(input, "%5d,", &array[i]);
    }
    fclose(input);

    result = zero_count(R, array);


    FILE *output;
    output = fopen("output.txt", "w+");
    fprintf(output, "Количество нулей в одномерном массиве: %d ", result);
    fclose(output);

    return 0;
}
