#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <cmath>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstring>

using namespace std;

class Calculator {
private:
    // Приоритеты операторов
    map<char, int> opPriority = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };
    
    // Список поддерживаемых функций
    vector<string> functions = {"sin", "cos", "tan", "ctg", "exp", "sqrt"};
    

    
    // Проверка корректности скобок
    bool checkParentheses(const string& expr) {
        int balance = 0;
        for (char c : expr) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    
    // Проверка на наличие двух операторов подряд
    bool checkConsecutiveOperators(const string& expr) {
        for (size_t i = 0; i < expr.length() - 1; i++) {
            if (strchr("+-*/^", expr[i]) && strchr("+-*/^", expr[i + 1])) {
                return false;
            }
        }
        return true;
    }
    
    // Проверка функций
    bool checkFunctions(const string& expr) {
        for (const string& func : functions) {
            size_t pos = 0;
            while ((pos = expr.find(func, pos)) != string::npos) {
                // Проверяем, что после имени функции идет '('
                if (pos + func.length() < expr.length()) {
                    if (expr[pos + func.length()] != '(') {
                        return false;
                    }
                } else {
                    return false;
                }
                pos += func.length();
            }
        }
        return true;
    }
    
    // Проверка на допустимые символы
    bool checkValidChars(const string& expr) {
        for (char c : expr) {
            if (!isalnum(c) && !strchr("+-*/.^()_", c) && c != ' ') {
                return false;
            }
        }
        return true;
    }
    
    // Проверка на наличие переменной x
    bool hasVariable(const string& expr) {
        return expr.find('x') != string::npos || expr.find('X') != string::npos;
    }

public:
    // Валидация выражения
    bool validateExpression(const string& expr, string& errorMsg) {
        // Удаляем пробелы для проверки
        string temp = expr;
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        
        if (temp.empty()) {
            errorMsg = "Empty expression";
            return false;
        }
        
        if (!checkValidChars(temp)) {
            errorMsg = "Unallowed symbols";
            return false;
        }
        
        if (!checkParentheses(temp)) {
            errorMsg = "Unpaired brackets";
            return false;
        }
        
        if (!checkConsecutiveOperators(temp)) {
            errorMsg = "2+ operators in a row";
            return false;
        }
        
        if (!checkFunctions(temp)) {
            errorMsg = "Wrong function use";
            return false;
        }
        
        return true;
    }

    bool isOperator(char c) {
        return opPriority.count(c) > 0;
    }

    // Проверка, является ли строка функцией
    bool isFunction(const string& token) {
        return find(functions.begin(), functions.end(), token) != functions.end();
    }
    
    // Преобразование в постфиксную запись
    vector<string> toPostfix(const string& expression) {
        vector<string> output;
        stack<string> opStack;
        string temp = expression;
        
        // Обработка унарного минуса
        size_t pos = 0;
        while ((pos = temp.find("(-", pos)) != string::npos) {
            temp.replace(pos, 2, "(0-");
            pos += 3;
        }
        if (temp[0] == '-') {
            temp = "0" + temp;
        }
        
        for (size_t i = 0; i < temp.length(); i++) {
            char c = temp[i];
            
            // Пропускаем пробелы
            if (c == ' ') continue;
            
            // Если цифра или точка (начало числа)
            if (isdigit(c) || c == '.') {
                string num;
                while (i < temp.length() && (isdigit(temp[i]) || temp[i] == '.')) {
                    num += temp[i++];
                }
                i--; // Возвращаемся на один символ назад
                output.push_back(num);
            }
            // Если переменная x
            else if (c == 'x' || c == 'X') {
                output.push_back("x");
            }
            // Если буква (начало функции)
            else if (isalpha(c)) {
                string func;
                while (i < temp.length() && isalpha(temp[i])) {
                    func += temp[i++];
                }
                i--; // Возвращаемся на один символ назад
                
                if (isFunction(func)) {
                    opStack.push(func);
                }
            }
            // Если открывающая скобка
            else if (c == '(') {
                opStack.push("(");
            }
            // Если закрывающая скобка
            else if (c == ')') {
                while (!opStack.empty() && opStack.top() != "(") {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop(); // Удаляем "("
                
                // Если на вершине стека функция
                if (!opStack.empty() && isFunction(opStack.top())) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
            }
            // Если оператор
            else if (opPriority.count(c)) {
                while (!opStack.empty() && opStack.top() != "(" &&
                       opPriority[opStack.top()[0]] >= opPriority[c]) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(string(1, c));
            }
        }
        
        // Выталкиваем оставшиеся операторы из стека
        while (!opStack.empty()) {
            output.push_back(opStack.top());
            opStack.pop();
        }
        
        return output;
    }
    
    // Вычисление постфиксного выражения
    double evaluatePostfix(const vector<string>& postfix, double x) {
        stack<double> values;
        
        for (const string& token : postfix) {
            // Если число
            if (isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
                values.push(stod(token));
            }
            // Если переменная x
            else if (token == "x") {
                values.push(x);
            }
            // Если оператор
            else if (token.length() == 1 && opPriority.count(token[0])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                
                switch (token[0]) {
                    case '+': values.push(a + b); break;
                    case '-': values.push(a - b); break;
                    case '*': values.push(a * b); break;
                    case '/': 
                        if (b == 0) throw runtime_error("Division by zero");
                        values.push(a / b); 
                        break;
                    case '^': values.push(pow(a, b)); break;
                }
            }
            // Если функция
            else if (isFunction(token)) {
                double val = values.top(); values.pop();
                
                if (token == "sin") values.push(sin(val));
                else if (token == "cos") values.push(cos(val));
                else if (token == "tan") values.push(tan(val));
                else if (token == "ctg") values.push(1.0 / tan(val));
                else if (token == "exp") values.push(exp(val));
                else if (token == "sqrt") {
                    if (val < 0) throw runtime_error("Negative number under square root");
                    values.push(sqrt(val));
                }
            }
        }
        
        return values.top();
    }
    
    // Основной метод вычисления
    double calculate(const string& expression, double x = 0) {
        vector<string> postfix = toPostfix(expression);
        return evaluatePostfix(postfix, x);
    }
};

void printPostfix(const vector<string>& postfix) {
    cout << "Постфиксная запись (ОПН): ";
    for (size_t i = 0; i < postfix.size(); i++) {
        cout << postfix[i];
        if (i < postfix.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    Calculator calc;
    string expression;
    
    cout << "=== Calculator ===" << endl;
    cout << "Operators: + - * / ^" << endl;
    cout << "Functions: sin, cos, tan, ctg, exp, sqrt" << endl;
    cout << "Variable: x" << endl;
    cout << "Example: cos(x-5)*10/(2*x-5)" << endl;
    cout << "\nWrite an expression: ";
    
    getline(cin, expression);
    
    // Валидация выражения
    string errorMsg;
    if (!calc.validateExpression(expression, errorMsg)) {
        cout << "Error: " << errorMsg << endl;
        return 1;
    }
    
    // Проверка наличия переменной x
    bool hasX = false;
    for (char c : expression) {
        if (c == 'x' || c == 'X') {
            hasX = true;
            break;
        }
    }
    
    double x = 0;
    if (hasX) {
        cout << "Input x: ";
        while (!(cin >> x)) {
            cout << "Error! Input a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    try {
        // Преобразуем в постфиксную запись
        vector<string> postfix = calc.toPostfix(expression);

        // Выводим постфиксную запись
        cout << "RPN: ";
        for (size_t i = 0; i < postfix.size(); i++) {
            cout << postfix[i];
            if (i < postfix.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;

        // Вычисляем результат
        double result = calc.evaluatePostfix(postfix, x);
        cout << "Result: " << result << endl;

    } catch (const exception& e) {
        cout << "\nCalculation error: " << e.what() << endl;
        return 1;
    }
    return 0;
}