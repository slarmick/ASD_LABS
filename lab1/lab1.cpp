#include <string>  
#include <stack>   
#include <iostream> 

using namespace std;

// Функция для проверки корректности строки с точки зрения баланса скобок
bool is_valid(const string& str) {
    stack<char> s;

    for (char c : str) {
        // Если символ является открывающей скобкой, помещаем его в стек
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // Если символ является закрывающей скобкой и соответствует последней открывающей скобке в стеке
        else if (c == ')' && !s.empty() && s.top() == '(') {
            s.pop();  // Удаляем последнюю открывающую скобку из стека
        }
        else if (c == '}' && !s.empty() && s.top() == '{') {
            s.pop();
        }
        else if (c == ']' && !s.empty() && s.top() == '[') {
            s.pop();
        }
        // Если символ не является скобкой или не соответствует последней открывающей скобке, строка некорректна
        else {
            return false;
        }
    }

    return s.empty();
}

int main() {
    setlocale(LC_ALL, "");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    if (is_valid(input)) {
        cout << "Строка существует" << endl;
    }
    else {
        cout << "Строка не существует" << endl;
    }

    return 0;
}