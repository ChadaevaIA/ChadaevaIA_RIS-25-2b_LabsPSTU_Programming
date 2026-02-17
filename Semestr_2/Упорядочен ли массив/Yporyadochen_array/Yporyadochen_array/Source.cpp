#include <iostream>
#include <clocale>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    const int n = 10;
    int A[n];
    bool f = true;

    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100 - 50;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n && f; i++) {
        if (A[i] < A[i - 1]) {
            f = false;
        }
    }

    if (f) {
        cout << "Массив упорядочен" << endl;
    }
    else {
        cout << "Массив не упорядочен" << endl;
    }

    return 0;
}
