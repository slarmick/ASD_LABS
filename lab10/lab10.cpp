#include <iostream>
#include <vector>

using namespace std;

// Функция для слияния двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Рекурсивная функция для сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем левую и правую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Слияние отсортированных половин
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}