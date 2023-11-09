#ifndef _INIT_H_
#define _INIT_H_

/**
 * Выводит содержимое одномерного массива в консоль
 * @param array {int*} - Массив, значения которого будут выведены в консоль
 * @param size {int} - Размер массива
 * @return {void} - Ничего не возвращает
 */
void print_array(int* array, int size);

/**
 * Выводит содержимое одномерного массива в консоль
 * @param array {int**} - Двумерный массив, значения которого будут выведены в консоль
 * @param rows {int} - Размер строки массива
 * @param columns {int} - Размер столбца массива
 * @return {void} - Ничего не возвращает
 */
void print_matrix(int** array, int rows, int columns);

/**
 * Выводит количество нулей в одномерном массиве в консоль
 * @param count {int} - Количество нулей
 * @return {void} - Ничего не возвращает
 */
// void print_result(int count);


#endif //_INIT_H_