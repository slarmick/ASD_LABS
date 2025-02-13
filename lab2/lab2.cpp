#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// Функция для определения приоритета операций
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Функция для выполнения арифметических операций
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw runtime_error("Деление на ноль");
        return a / b;
    default: throw runtime_error("Недопустимый оператор");
    }
}

// Функция для вычисления выражения
int evaluate(string expression) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < expression.length(); i++) {
        // Пропускаем пробелы
        if (expression[i] == ' ') continue;

        // Если текущий символ - цифра, считываем всё число
        if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // Возвращаемся на один символ назад, так как цикл for тоже увеличивает i
        }

        // Если текущий символ - открывающая скобка, помещаем её в стек операций
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }

        // Если текущий символ - закрывающая скобка, вычисляем выражение внутри скобок
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (values.size() < 2) throw runtime_error("Неверная запись");

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Убираем открывающую скобку из стека
            if (!ops.empty() && ops.top() == '(') {
                ops.pop();
            }
            else {
                throw runtime_error("Пропустил скобки");
            }
        }

        // Если текущий символ - операция
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Пока операция на вершине стека имеет больший или равный приоритет,
            // выполняем операцию и помещаем результат обратно в стек значений
            while (!ops.empty() && priority(ops.top()) >= priority(expression[i])) {
                if (values.size() < 2) throw runtime_error("Неверная запись");

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Помещаем текущую операцию в стек операций
            ops.push(expression[i]);
        }

        // Если символ не распознан
        else {
            throw runtime_error("Неопознанный символ");
        }
    }

    // Выполняем оставшиеся операции
    while (!ops.empty()) {
        if (values.size() < 2) throw runtime_error("Неверная запись");

        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Результат выражения находится на вершине стека значений
    if (values.size() != 1) throw runtime_error("Неверная запись");

    return values.top();
}

int main() {
    setlocale(LC_ALL, "");
    string expression;
    cout << "Введите выражение: ";
    getline(cin, expression);

    try {
        // Убедимся, что выражение заканчивается на '='
        if (expression.back() != '=') {
            throw runtime_error("Где '='");
        }
        // Убираем '=' из выражения
        expression.pop_back();

        int result = evaluate(expression);
        cout << "Результат: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}