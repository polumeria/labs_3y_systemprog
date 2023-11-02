// Лабораторная работа №4
// Работа со структурами.
// Необходимо создать структуру, описывающую предмет 
// в мире по варианту, несколько объектов, и продемонстрировать их 
// функциональность. 
// Структура обязана содержать статическую переменную, 
// динамическую переменную, статический массив, динамический массив, 
// указатель на функцию, другую структуру (любую какую придумаете). 
// Варианты структур:
// 1. Студент;

#include <stdio.h>
#include <time.h>
#include <malloc.h>

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

void print_mark(struct Journal Mark){
    printf("%s: %i\n", Mark.subject, Mark.mark);
};

void print_student(struct Student Student)
{
    printf("Фио: %s\n", Student.full_name);
    printf("Возраст: %i\n", Student.age);
    printf("Группа: %s\n", Student.group);
    printf("Оценки: \n");
    print_mark(Student.Mark);
};

int main() {    
    struct Student March;
    March.full_name = (char*)malloc(100 * sizeof(char));
    March.full_name = "Громова Марта";
    March.age = 25;
    March.group = "02441-ДБ";
    March.Mark.subject = "математическое моделирование";
    March.Mark.mark = 5;
       
    print_student(March);
    return 0;
};