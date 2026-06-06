#include "Header.h"

// Функция для обмена элементами
void swap_int(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Разделение массива (partition)
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент — последний
    int i = low - 1;       // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap_int(arr[i], arr[j]);
        }
    }
    swap_int(arr[i + 1], arr[high]);
    return i + 1;
}

// Рекурсивная функция быстрой сортировки
void quick_sort_recursive(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

// Основная функция сортировки
void quick_sort(int* arr, int size) {
    if (!arr || size < 0) {
        throw invalid_argument("Некорректные входные данные");
    }
    if (size > 1) {
        quick_sort_recursive(arr, 0, size - 1);
    }
}

// Функция для вывода массива
void print_array2(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "\n";
}

bool task_2() {
    // Тестовые массивы
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int sizes[] = { 10, 15, 18 };
    int* arrays[] = { arr1, arr2, arr3 };

    for (int t = 0; t < 3; t++) {
        cout << "Исходный массив: ";
        print_array2(arrays[t], sizes[t]);

        quick_sort(arrays[t], sizes[t]);

        cout << "Отсортированный массив: ";
        print_array2(arrays[t], sizes[t]);
    }

    return 0;
}
