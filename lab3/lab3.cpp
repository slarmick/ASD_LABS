#include <iostream>  
#include <cmath>     
#include <set>       

using namespace std;

int main() {
    int x;  
    cin >> x;  

    set<int> results;  // Используем set для хранения уникальных чисел, удовлетворяющих условию

    for (int k = 0; pow(3, k) <= x; ++k) {
        for (int l = 0; pow(3, k) * pow(5, l) <= x; ++l) {
            for (int m = 0; pow(3, k) * pow(5, l) * pow(7, m) <= x; ++m) {
                // Вычисляем значение 3^K * 5^L * 7^M
                int value = pow(3, k) * pow(5, l) * pow(7, m);

                // Проверяем, находится ли вычисленное значение в диапазоне от 1 до x
                if (value >= 1 && value <= x) {
                    // Добавляем значение в set, чтобы избежать дубликатов
                    results.insert(value);
                }
            }
        }
    }

    // Выводим все числа, удовлетворяющие условию
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0; 
}
