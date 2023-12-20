// Лабораторная работа №9
// Продвинутая работа с бинарными файлами
// Оформить соответствующие варианты для 4 лабораторной работы так, 
// чтобы исходные данные брались из бинарного файла input.bin, а 
// ответ выводился в бинарный файл output.bin

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Journal{
    char* subject;
    int mark;
};

struct Student {
    int age;
    struct Journal Mark;
    char* full_name;
    char* group;
    void (*print_student)(struct Student);
};


int main()
{
    char full_name[26];
    char group[11]; 
    char subject[28];
    int age, grade;

    struct Student March;
    March.full_name = (char*)malloc(100 * sizeof(char));
    March.full_name = "Grom March";
    March.age = 25;
    March.group = "02441-DB";
    March.Mark.subject = "math modeling";
    March.Mark.mark = 5;
       
    FILE* input;
    input = fopen("../input.bin", "wb+");
    fwrite(March.full_name, sizeof(char), 26, input);
    fwrite(&March.age, sizeof(int), 1, input);
    fwrite(March.group, sizeof(char),11, input);
    fwrite(March.Mark.subject, sizeof(char), 28, input);
    fwrite(&March.Mark.mark, sizeof(int), 1, input);
    fclose(input);

    input = fopen("../input.bin", "rb");
    fread(full_name, sizeof(char), 26, input);
    fread(&age, sizeof(int), 1, input);
    fread(group, sizeof(char), 11, input);
    fread(subject, sizeof(char), 28, input);
    fread(&grade, sizeof(int), 1, input);
    fclose(input);

    struct Student April;
    April.full_name = full_name;
    April.age = age;
    April.group = group;
    April.Mark.subject = subject;
    April.Mark.mark = grade;

    FILE *output;
    output = fopen("output.bin", "wb+");
    fwrite(April.full_name, sizeof(char), 26, output);
    fwrite(&April.age, sizeof(int), 1, output);
    fwrite(April.group, sizeof(char), 11, output);
    fwrite(April.Mark.subject, sizeof(char), 28, output);
    fwrite(&April.Mark.mark, sizeof(int), 1, output);
    fclose(output);

    output = fopen("output.bin", "rb");
    fread(full_name, sizeof(char), 26, output);
    fread(&age, sizeof(int), 1, output);
    fread(group, sizeof(char), 11, output);
    fread(subject, sizeof(char), 28, output);
    fread(&grade, sizeof(int), 1, output);
    fclose(output);

    printf("fio: %s\n", full_name);
    printf("age: %i\n", age);
    printf("group: %s\n", group);
    printf("marks: \n");
    printf("%s: %i\n", subject, grade);

    return 0;
}
