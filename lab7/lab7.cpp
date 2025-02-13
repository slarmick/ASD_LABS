#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Начальное значение шага
    int gap = n / 2;

    // Пока шаг больше 0
    while (gap > 0) {
        // Внешний цикл: перебирает элементы с шагом gap
        for (int i = gap; i < n; i++) {
            // Внутренний цикл: вставляет элемент arr[i] в отсортированную подпоследовательность
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        // Уменьшаем шаг
        gap /= 2;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> arr;
    string input;

    cout << "Введите числа (введите пустую строку для завершения): ";

    // Ввод чисел с клавиатуры
    getline(cin, input); // Считываем первую строку
    while (!input.empty()) {
        // Разбиваем строку на числа
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        getline(cin, input); // Считываем следующую строку
    }

    cout << "Исходная последовательность: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
