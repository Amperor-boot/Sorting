#include "Header.h"

// Функция сортировки подсчётом
void count_sort(int* arr, int size) {
    if (!arr || size < 0) {
        throw invalid_argument("Некорректные входные данные");
    }
    if (size <= 1) return;

    const int MIN_VAL = 10;
    const int MAX_VAL = 24;
    const int RANGE = MAX_VAL - MIN_VAL + 1;

    // Массив для подсчёта количества каждого числа
    int count[RANGE] = { 0 };

    // Подсчёт вхождений
    for (int i = 0; i < size; i++) {
        if (arr[i] < MIN_VAL || arr[i] > MAX_VAL) {
            throw out_of_range("Элемент массива выходит за допустимый диапазон [10, 24]");
        }
        count[arr[i] - MIN_VAL]++;
    }

    // Запись отсортированных значений обратно в массив
    int index = 0;
    for (int i = 0; i < RANGE; i++) {
        while (count[i] > 0) {
            arr[index++] = i + MIN_VAL;
            count[i]--;
        }
    }
}

// Функция для вывода массива
void print_array3(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "\n";
}

bool task_3() {
    // Тестовые массивы
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

    int sizes[] = { 30, 40, 45 };
    int* arrays[] = { arr1, arr2, arr3 };

    for (int t = 0; t < 3; t++) {
        cout << "Исходный массив: ";
        print_array3(arrays[t], sizes[t]);

        count_sort(arrays[t], sizes[t]);

        cout << "Отсортированный массив: ";
        print_array3(arrays[t], sizes[t]);
    }

    return 0;
}
