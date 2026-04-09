#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next = nullptr;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
};

// добавление в конец
void pushBack(Queue& q, string data) {
    Node* n = new Node;
    n->data = data;

    if (!q.head) {
        q.head = q.tail = n;
    }
    else {
        q.tail->next = n;
        q.tail = n;
    }
}

// добавление в начало
void pushFront(Queue& q, string data) {
    Node* n = new Node;
    n->data = data;

    n->next = q.head;
    q.head = n;

    if (!q.tail) 
    {
        q.tail = n;
    }
}

// удаление из начала
void popFront(Queue& q) {
    if (!q.head) 
    {
        return;
    }

    Node* tmp = q.head;
    q.head = q.head->next;

    if (!q.head) 
    {
        q.tail = nullptr;
    }

    delete tmp;
}

// удаление из конца
void popBack(Queue& q) {
    if (!q.head) 
    {
        return;
    }

    if (q.head == q.tail) {
        delete q.head;
        q.head = q.tail = nullptr;
        return;
    }

    Node* cur = q.head;
    while (cur->next != q.tail)
    {
        cur = cur->next;
    }

    delete q.tail;
    cur->next = nullptr;
    q.tail = cur;
}

// удаление по ключу
void deleteByKey(Queue& q, string key) {
    Node* cur = q.head;
    Node* prev = nullptr;

    while (cur) {
        if (cur->data == key) {
            if (prev) 
            {
                prev->next = cur->next;
            }
            else 
            {
                q.head = cur->next;
            }

            if (cur == q.tail)
            {
                q.tail = prev;
            }

            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// удаление по номеру
void deleteAt(Queue& q, int index) {
    if (!q.head || index < 1) 
    {
        return;
    }

    if (index == 1) {
        popFront(q);
        return;
    }

    Node* cur = q.head;
    for (int i = 1; i < index - 1 && cur->next; i++)
    {
        cur = cur->next;
    }

    if (!cur->next) 
    {
        return;
    }

    Node* tmp = cur->next;
    cur->next = tmp->next;

    if (tmp == q.tail)
    {
        q.tail = cur;
    }

    delete tmp;
}

// вставка по номеру
void insertAt(Queue& q, int index, string data) {
    if (index == 1) {
        pushFront(q, data);
        return;
    }

    Node* cur = q.head;
    for (int i = 1; i < index - 1 && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur) 
    {
        return;
    }

    Node* n = new Node;
    n->data = data;

    n->next = cur->next;
    cur->next = n;

    if (!n->next)
    {
        q.tail = n;
    }
}

// вставка перед ключом
void insertByKey(Queue& q, string key, string data) {
    Node* cur = q.head;
    Node* prev = nullptr;

    while (cur) {
        if (cur->data == key) {
            Node* n = new Node;
            n->data = data;

            if (prev)
            {
                prev->next = n;
            }
            else
            {
                q.head = n;
            }

            n->next = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// вывод
void printQueue(Queue& q) {
    if (!q.head) {
        cout << "Очередь пуста\n";
        return;
    }

    Node* cur = q.head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    system("cls");
    system("chcp 1251");
    Queue q;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pushBack(q, s);
    }

    cout << "\nОчередь: ";
    printQueue(q);

    string s;

    cout << "\nДобавление в начало: ";
    cin >> s;
    pushFront(q, s);
    printQueue(q);

    cout << "\nДобавление в конец: ";
    cin >> s;
    pushBack(q, s);
    printQueue(q);

    cout << "\nУдаление с начала:\n";
    popFront(q);
    printQueue(q);

    cout << "\nУдаление с конца:\n";
    popBack(q);
    printQueue(q);

    cout << "\nУдаление по ключу: ";
    cin >> s;
    deleteByKey(q, s);
    printQueue(q);

    int k;
    cout << "\nУдаление по номеру: ";
    cin >> k;
    deleteAt(q, k);
    printQueue(q);

    cout << "\nВставка по номеру:\n";
    cin >> k >> s;
    insertAt(q, k, s);
    printQueue(q);

    cout << "\nВставка перед ключом:\n";
    cin >> s;
    string val;
    cin >> val;
    insertByKey(q, s, val);
    printQueue(q);

    return 0;
}