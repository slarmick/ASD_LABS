#include <iostream>
#include <vector>
#include <algorithm>

// Вспомогательная функция для сортировки подсчетом по определенному разряду
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // Выходной массив
    std::vector<int> count(10, 0); // Массив для подсчета

    // Подсчет количества вхождений каждой цифры
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Изменение count[i] так, чтобы он содержал фактическую позицию цифры в output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Построение выходного массива
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Копирование отсортированного массива обратно в arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Основная функция для поразрядной сортировки
void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Находим максимальное число, чтобы определить количество разрядов
    int max_num = *std::max_element(arr.begin(), arr.end());

    // Применяем сортировку подсчетом для каждого разряда
    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr;
    int n;

    std::cout << "Введите количество чисел: ";
    std::cin >> n;

    std::cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    // Вызов поразрядной сортировки
    radixSort(arr);

    // Вывод отсортированного массива
    std::cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}