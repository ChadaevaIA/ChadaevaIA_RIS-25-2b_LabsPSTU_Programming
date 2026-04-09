#include <iostream>
#include <clocale>
using namespace std;

// узел стека
struct StackNode {
    char data;          
    StackNode* next;    // указатель на следующий элемент
};

// добавление в стек
void push(StackNode*& top, char ch) {
    StackNode* node = new StackNode;
    node->data = ch;
    node->next = top;
    top = node;
}

// удаление из стека
char pop(StackNode*& top) {
    if (!top) return '\0';
    StackNode* temp = top;
    char ch = temp->data;
    top = top->next;
    delete temp;
    return ch;
}

// проверка соответствия скобок
bool isMatch(char open, char close) {
    if (open == '(' && close == ')') 
    {
        return true;
    }
    if (open == '{' && close == '}') 
    {
        return true;
    }
    if (open == '[' && close == ']') 
    {
        return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "ru");

    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    StackNode* stack = nullptr;
    bool error = false;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // открывающие скобки
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        }
        // закрывающие скобки
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (!stack) {
                cout << "Ошибка: лишняя закрывающая скобка\n";
                error = true;
                break;
            }

            char open = pop(stack);
            if (!isMatch(open, ch)) {
                cout << "Ошибка: скобки не совпадают\n";
                error = true;
                break;
            }
        }
    }

    if (!error) {
        if (stack) {
            cout << "Ошибка: есть незакрытые скобки\n";
        }
        else {
            cout << "Все скобки расставлены правильно\n";
        }
    }

    // очистка памяти
    while (stack) pop(stack);

    return 0;
}