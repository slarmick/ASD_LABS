#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size(); // Размер массива

    // Проходим по массиву, начиная с первого элемента
    for (int i = 0; i < n - 1; ++i) {
        // Индекс минимального элемента
        int minIndex = i;

        // Находим минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Меняем местами минимальный элемент с текущим элементом
        swap(arr[minIndex], arr[i]);
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

    selectionSort(numbers); // Вызываем функцию сортировки

    cout << "Отсортированный массив (метод выбора): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}