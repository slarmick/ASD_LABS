#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки вставками
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // Размер массива

    // Проходим по массиву, начиная со второго элемента
    for (int i = 1; i < n; ++i) {
        // Сохраняем текущий элемент в переменную key
        int key = arr[i];
        // Индекс для сравнения с предыдущими элементами
        int j = i - 1;

        // Пока j >= 0 и key меньше предыдущего элемента, сдвигаем элементы вправо
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j]; // Сдвигаем элемент вправо
            --j; // Переходим к следующему предыдущему элементу
        }

        // Вставляем key на его правильное место
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << "Исходный массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(numbers); // Вызываем функцию сортировки

    cout << "Отсортированный массив (метод вставками): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}