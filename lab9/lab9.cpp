#include <iostream>
#include <vector>

// Функция для преобразования поддерева с корнем в узле i в кучу
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для выполнения пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
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

    heapSort(arr);

    std::cout << "Отсортированная последовательность: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}