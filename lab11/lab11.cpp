#include <iostream>
#include <vector>

using namespace std;

// Функция для разбиения массива
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент как опорный
    int i = (low - 1); // Индекс элемента, меньшего, чем опорный

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Меняем местами опорный элемент с элементом на i + 1
    return (i + 1); // Возвращаем позицию опорного элемента
}

// Рекурсивная функция для быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Разбиваем массив на две части
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем левую и правую части
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    vector<int> arr;
    int num;

    cout << "Введите числа (введите -1 для завершения ввода): ";

    // Ввод чисел с клавиатуры
    cin >> num;
    while (num != -1) {
        arr.push_back(num);
        cin >> num;
    }

    cout << "Исходная последовательность: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}