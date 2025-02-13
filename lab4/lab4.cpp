#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки методом прочесывания (Comb Sort)
void combSort(vector<int>& arr) {
    int n = arr.size(); // Размер массива
    int gap = n; // Начальный шаг прочесывания
    bool swapped = true; // Флаг для отслеживания перестановок

    // Цикл продолжается, пока шаг больше 1 или произошла перестановка
    while (gap > 1 || swapped) {
        // Уменьшаем шаг в 1.3 раза
        gap = max(1, (int)(gap / 1.3));
        swapped = false; // Сбрасываем флаг перестановок

        // Проходимся по массиву с текущим шагом
        for (int i = 0; i + gap < n; i++) {
            // Если соседние элементы не упорядочены, меняем их местами
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true; // Устанавливаем флаг перестановок
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> numbers(n); // Создаем вектор нужного размера
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i]; // Считываем элементы с клавиатуры
    }

    cout << "Исходный массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    combSort(numbers); // Вызываем функцию сортировки

    cout << "Отсортированный массив (метод прочесывания): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}