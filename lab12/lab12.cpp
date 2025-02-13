#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для слияния двух отсортированных векторов
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    size_t i = 0, j = 0;

    // Слияние двух векторов
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        }
        else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Добавляем оставшиеся элементы из левого вектора
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    // Добавляем оставшиеся элементы из правого вектора
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Функция для многофазовой сортировки
vector<int> multiwayMergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    // Разделяем массив на две части
    size_t mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Рекурсивно сортируем каждую часть
    left = multiwayMergeSort(left);
    right = multiwayMergeSort(right);

    // Сливаем отсортированные части
    return merge(left, right);
}

int main() {
    setlocale(LC_ALL, "");
    vector<int> numbers;
    int num;

    cout << "Введите последовательность чисел (для завершения введите любой нечисловой символ):" << endl;

    // Чтение чисел с клавиатуры
    while (cin >> num) {
        numbers.push_back(num);
    }

    // Сортировка последовательности
    vector<int> sortedNumbers = multiwayMergeSort(numbers);

    // Вывод отсортированной последовательности
    cout << "Отсортированная последовательность:" << endl;
    for (int n : sortedNumbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}