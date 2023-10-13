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
#include <time.h>

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

int main() {
    srand(time(NULL));

 
    float (*array_of_actions[4])(float, float) = 
        {add, subtract, multiply, divide}; 
    float a, b, result;
    int action;
    // float (*add_ptr)(float, float);
    // float (*subtract_ptr)(float, float);
    // float (*multiply_ptr)(float, float);
    // float (*divide_ptr)(float, float);

    printf("Введите два числа: \n");
    scanf("%f%f", &a, &b);
    printf("\n");
    printf("Введите номер действия где \n1 - сложение \n2 - вычитание \n3 - умножение \n4 - деление \n\n");
    while (action < 1 ||
           action > 4)
    {
        scanf("%d", &action);
        if (action < 1 || action > 4)
            printf("Введен неверный номер действия\n");
    }
    
    // scanf("%d", &action);
    // printf("\n");

    // add_ptr = add;
    // subtract_ptr = subtract;
    // multiply_ptr = multiply;
    // divide_ptr = divide;

    switch(action)
    {
            case 1:
                result = array_of_actions[0](a, b);
                break;
            case 2:
                    result = array_of_actions[1](a, b);
                    break;
            case 3:
                result = array_of_actions[2](a, b);
                break;
            case 4:
                result = array_of_actions[3](a, b);
                break;
            default: printf("что-то пошло не так");
    }



    printf("\nрезультат: %f ", result);
    printf("\n \n"); 
}        



float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}