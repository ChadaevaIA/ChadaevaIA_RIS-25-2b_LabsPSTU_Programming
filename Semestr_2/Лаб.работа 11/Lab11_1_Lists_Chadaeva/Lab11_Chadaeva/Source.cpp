#include <iostream>
#include <string>

using namespace std;

// ---------- ОДНОСВЯЗНЫЙ ----------

struct Node1 {
    string data;
    Node1* next;
};

struct List1 {
    Node1* head = nullptr;
};

// добавление в конец
void pushBack1(List1& list, string data) {
    Node1* new_node = new Node1;
    new_node->data = data;
    new_node->next = nullptr;

    if (!list.head) {
        list.head = new_node;
    }
    else {
        Node1* cur = list.head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

// добавление в начало
void pushFront1(List1& list, string data) {
    Node1* new_node = new Node1;
    new_node->data = data;
    new_node->next = list.head;
    list.head = new_node;
}

// удаление с начала
void deleteFront1(List1& list) {
    if (!list.head) 
    {
        return;
    }
    Node1* temp = list.head;
    list.head = list.head->next;
    delete temp;
}

// удаление с конца
void deleteBack1(List1& list) {
    if (!list.head) 
    {
        return;
    }

    if (!list.head->next) {
        delete list.head;
        list.head = nullptr;
        return;
    }

    Node1* cur = list.head;
    while (cur->next->next)
    {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
}

// удаление по ключу
void deleteByKey1(List1& list, string key) {
    Node1* cur = list.head;
    Node1* prev = nullptr;

    while (cur) {
        if (cur->data == key) {
            if (prev)
            {
                prev->next = cur->next;
            }
            else
            {
                list.head = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// удаление по индексу
void deleteAt1(List1& list, int index) {
    if (!list.head || index < 1) 
    {
        return;
    }

    if (index == 1) {
        deleteFront1(list);
        return;
    }

    Node1* cur = list.head;
    for (int i = 1; i < index - 1 && cur->next; i++)
    {
        cur = cur->next;
    }

    if (!cur->next)
    {
        return;
    }

    Node1* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

// вставка по индексу
void insertAt1(List1& list, int index, string data) {
    if (index == 1) {
        pushFront1(list, data);
        return;
    }

    Node1* cur = list.head;
    for (int i = 1; i < index - 1 && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur) 
    {
        return;
    }

    Node1* new_node = new Node1;
    new_node->data = data;
    new_node->next = cur->next;
    cur->next = new_node;
}

// вставка по ключу (перед)
void insertByKey1(List1& list, string key, string data) {
    Node1* cur = list.head;
    Node1* prev = nullptr;

    while (cur) {
        if (cur->data == key) {
            Node1* new_node = new Node1;
            new_node->data = data;

            if (prev)
            {
                prev->next = new_node;
            }
            else
            {
                list.head = new_node;
            }

            new_node->next = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// вывод
void print1(List1& list) {
    Node1* cur = list.head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// ---------- ДВУСВЯЗНЫЙ ----------

struct Node2 {
    string data;
    Node2* next;
    Node2* prev;
};

struct List2 {
    Node2* head = nullptr;
    Node2* tail = nullptr;
};

// добавление в конец
void pushBack2(List2& list, string data) {
    Node2* new_node = new Node2;
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = list.tail;

    if (!list.head)
    {
        list.head = new_node;
    }
    else
    {
        list.tail->next = new_node;
    }

    list.tail = new_node;
}

// добавление в начало
void pushFront2(List2& list, string data) {
    Node2* new_node = new Node2;
    new_node->data = data;
    new_node->prev = nullptr;
    new_node->next = list.head;

    if (list.head)
    {
        list.head->prev = new_node;
    }
    else
    {
        list.tail = new_node;
    }

    list.head = new_node;
}

// удаление с начала
void deleteFront2(List2& list) {
    if (!list.head) 
    {
        return;
    }

    Node2* temp = list.head;
    list.head = list.head->next;

    if (list.head)
    {
        list.head->prev = nullptr;
    }
    else
    {
        list.tail = nullptr;
    }

    delete temp;
}

// удаление с конца
void deleteBack2(List2& list) {
    if (!list.tail)
    {
        return;
    }

    Node2* temp = list.tail;
    list.tail = list.tail->prev;

    if (list.tail)
    {
        list.tail->next = nullptr;
    }
    else
    {
        list.head = nullptr;
    }

    delete temp;
}

// удаление по ключу
void deleteByKey2(List2& list, string key) {
    Node2* cur = list.head;

    while (cur) {
        if (cur->data == key) {
            if (cur->prev)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                list.head = cur->next;
            }

            if (cur->next)
            {
                cur->next->prev = cur->prev;
            }
            else
            {
                list.tail = cur->prev;
            }

            delete cur;
            return;
        }
        cur = cur->next;
    }
}

// удаление по индексу
void deleteAt2(List2& list, int index) {
    if (!list.head || index < 1) 
    {
        return;
    }

    Node2* cur = list.head;
    for (int i = 1; i < index && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur) 
    {
        return;
    }

    if (cur->prev)
    {
        cur->prev->next = cur->next;
    }
    else
    {
        list.head = cur->next;
    }

    if (cur->next)
    {
        cur->next->prev = cur->prev;
    }
    else
    {
        list.tail = cur->prev;
    }

    delete cur;
}

// вставка по индексу
void insertAt2(List2& list, int index, string data) {
    if (index == 1) {
        pushFront2(list, data);
        return;
    }

    Node2* cur = list.head;
    for (int i = 1; i < index - 1 && cur; i++)
    {
        cur = cur->next;
    }

    if (!cur) 
    {
        return;
    }

    Node2* new_node = new Node2;
    new_node->data = data;

    new_node->next = cur->next;
    new_node->prev = cur;

    if (cur->next)
    {
        cur->next->prev = new_node;
    }
    else
    {
        list.tail = new_node;
    }

    cur->next = new_node;
}

// вставка по ключу
void insertByKey2(List2& list, string key, string data) {
    Node2* cur = list.head;

    while (cur) {
        if (cur->data == key) {
            Node2* new_node = new Node2;
            new_node->data = data;

            new_node->next = cur;
            new_node->prev = cur->prev;

            if (cur->prev)
            {
                cur->prev->next = new_node;
            }
            else
            {
                list.head = new_node;
            }

            cur->prev = new_node;
            return;
        }
        cur = cur->next;
    }
}

// вывод
void print2(List2& list) {
    Node2* cur = list.head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");
    List1 list1;
    List2 list2;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pushBack1(list1, s);
        pushBack2(list2, s);
    }

    cout << "\nОднонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    // добавление в начало
    string x;
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> x;

    pushFront1(list1, x);
    pushFront2(list2, x);

    cout << "После добавления в начало:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    // удаление по ключу
    string key;
    cout << "\nВведите ключ для удаления: ";
    cin >> key;

    deleteByKey1(list1, key);
    deleteByKey2(list2, key);

    cout << "После удаления по ключу:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    // вставка по индексу
    int index;
    cout << "\nВведите индекс для вставки: ";
    cin >> index;
    cout << "Введите элемент: ";
    cin >> x;

    insertAt1(list1, index, x);
    insertAt2(list2, index, x);

    cout << "После вставки по индексу:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    // удаление по индексу
    cout << "\nВведите индекс для удаления: ";
    cin >> index;

    deleteAt1(list1, index);
    deleteAt2(list2, index);

    cout << "После удаления по индексу:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    // удаление с начала
    deleteFront1(list1);
    deleteFront2(list2);

    cout << "\nПосле удаления с начала:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    //удаление с конца
    deleteBack1(list1);
    deleteBack2(list2);

    cout << "\nПосле удаления с конца:\n";
    cout << "Однонаправленный: ";
    print1(list1);
    cout << "Двунаправленный: ";
    print2(list2);

    return 0;
}