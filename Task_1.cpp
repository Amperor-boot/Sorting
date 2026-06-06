#include "Header.h"

// Функция для слияния двух отсортированных частей массива
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Временные массивы
    vector<int> L(n1), R(n2);

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Индексы для обхода временных массивов
    int i = 0, j = 0, k = left;

    // Слияние обратно в arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Рекурсивная функция сортировки слиянием
void merge_sort_recursive(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Основная функция сортировки
void merge_sort(int* arr, int size) {
    if (!arr || size < 0) {
        throw invalid_argument("Некорректные входные данные");
    }
    if (size > 1) {
        merge_sort_recursive(arr, 0, size - 1);
    }
}

// Функция для вывода массива
void print_array1(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "\n";
}

bool task_1() {
    // Тестовые массивы
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int sizes[] = { 10, 15, 18 };
    int* arrays[] = { arr1, arr2, arr3 };

    for (int t = 0; t < 3; t++) {
        cout << "Исходный массив: ";
        print_array1(arrays[t], sizes[t]);

        merge_sort(arrays[t], sizes[t]);

        cout << "Отсортированный массив: ";
        print_array1(arrays[t], sizes[t]);
    }

    return 0;
}
