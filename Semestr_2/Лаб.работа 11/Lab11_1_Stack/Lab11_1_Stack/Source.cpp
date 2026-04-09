#include <iostream>
#include <string>

using namespace std;

struct StackNode {
    string key;
    StackNode* next;
};

// создание узла
StackNode* createNode(const string& str) {
    StackNode* node = new StackNode;
    node->key = str;
    node->next = nullptr;
    return node;
}

// инициализация
void initStack(StackNode*& top) {
    top = nullptr;
}

// добавление в начало (push)
void pushFront(StackNode*& top, const string& key) {
    StackNode* node = createNode(key);
    node->next = top;
    top = node;
}

// добавление в конец
void pushBack(StackNode*& top, const string& key) {
    StackNode* node = createNode(key);

    if (!top) {
        top = node;
        return;
    }

    StackNode* cur = top;
    while (cur->next)
    {
        cur = cur->next;
    }

    cur->next = node;
}

// удаление с начала
void popFront(StackNode*& top) {
    if (!top) 
    {
        return;
    }

    StackNode* tmp = top;
    top = top->next;
    delete tmp;
}

// удаление с конца
void popBack(StackNode*& top) {
    if (!top) 
    {
        return;
    }

    if (!top->next) {
        delete top;
        top = nullptr;
        return;
    }

    StackNode* cur = top;
    while (cur->next->next)
    {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
}

// удаление по ключу
bool deleteByKey(StackNode*& top, const string& key) {
    StackNode* cur = top;
    StackNode* prev = nullptr;

    while (cur) {
        if (cur->key == key) {
            if (prev) 
            {
                prev->next = cur->next;
            }
            else 
            {
                top = cur->next;
            }

            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

//  удаление по номеру
void deleteByIndex(StackNode*& top, int index) {
    if (index < 1 || !top) 
    {
        return;
    }

    if (index == 1) {
        popFront(top);
        return;
    }

    StackNode* cur = top;

    for (int i = 1; i < index - 1 && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur || !cur->next) 
    {
        return;
    }

    StackNode* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

// вставка по номеру
void insertByIndex(StackNode*& top, int index, const string& key) {
    if (index <= 1) {
        pushFront(top, key);
        return;
    }

    StackNode* cur = top;

    for (int i = 1; i < index - 1 && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur) 
    {
        return;
    }

    StackNode* node = createNode(key);
    node->next = cur->next;
    cur->next = node;
}

// вставка по ключу (перед элементом)
void insertBeforeKey(StackNode*& top, const string& key, const string& newKey) {
    StackNode* cur = top;
    StackNode* prev = nullptr;

    while (cur) {
        if (cur->key == key) {
            StackNode* node = createNode(newKey);

            if (prev) {
                prev->next = node;
                node->next = cur;
            }
            else {
                node->next = top;
                top = node;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// вывод
void printStack(StackNode* top) {
    if (!top) {
        cout << "Стек пуст\n";
        return;
    }

    while (top) {
        cout << top->key << " ";
        top = top->next;
    }
    cout << "\n";
}

// очистка
void destroy(StackNode*& top) {
    while (top)
    {
        popFront(top);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    system("cls");
    system("chcp 1251");

    StackNode* stack;
    initStack(stack);

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        pushFront(stack, x);
    }

    cout << "Стек: ";
    printStack(stack);

    string x;
    cout << "\nДобавление в конец: ";
    cin >> x;
    pushBack(stack, x);
    printStack(stack);

    cout << "\nУдаление с начала:\n";
    popFront(stack);
    printStack(stack);

    cout << "\nУдаление с конца:\n";
    popBack(stack);
    printStack(stack);

    cout << "\nУдаление по ключу: ";
    cin >> x;
    deleteByKey(stack, x);
    printStack(stack);

    int index;
    cout << "\nУдаление по номеру: ";
    cin >> index;
    deleteByIndex(stack, index);
    printStack(stack);

    cout << "\nВставка по номеру: ";
    cin >> index >> x;
    insertByIndex(stack, index, x);
    printStack(stack);

    string key;
    cout << "\nВставка перед ключом (ключ + новый): ";
    cin >> key >> x;
    insertBeforeKey(stack, key, x);
    printStack(stack);

    destroy(stack);
    cout << "После очистки:\n";
    printStack(stack);

    return 0;
}