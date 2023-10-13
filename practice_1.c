// Создать одномерный массив с целыми числами. Составить еще один одномерный массив, 
// который будет содержать только положительные числа из исходного массива


#include <stdio.h>
#include <malloc.h>

int main()
{
    int *array;
    int *result_array;
    int size;
    int count = 0;

    printf(" Введите размер динамического массива: ");
    scanf("%d", &size);
    printf("\n");

    array = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            count++;
        }
    }

    result_array = (int *)malloc(count * sizeof(int));
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            result_array[j] = array[i];
            j++;
        }
    }

    printf(" Исходный динамический массив: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    printf("\n \n");
    printf(" Одномерный массив положительных чисел: \n");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", result_array[i]);
    }

    printf("\n");
    printf("\n");

 
    free(result_array);
    return 0;
}
