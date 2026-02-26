#include <iostream>
#include <clocale>
#include <iomanip> 

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int n = 10;
    const int m = 10;
    int z;

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 200 - 100;
        }
    }
    cout << "Введите число для поиска: ";
    cin >> z;
    int count = 0;

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j = 0; j < m; j++) {
            cout << setw(4) << A[i][j];
            if (A[i][j] == z) {
                f = true;
            }
        }
        if (!f) {
            count++;
        }
        cout << endl;
    }


    int** new_A = new int* [count];
    int ii = 0;

    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j = 0; j < m && !f; j++) {
            if (A[i][j] == z) {
                f = true;
            }
        }

        if (!f) {
            new_A[ii] = new int[m];
            for (int j = 0; j < m; j++) {
                new_A[ii][j] = A[i][j];
            }
            ii++;
        }
        delete[] A[i];


    }

    delete[] A;
    A = nullptr;


    if (count > 0) {
        cout << "Массив после удаления строк, содержащих " << z << ":" << endl;
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < m; j++) {
                cout << setw(4) << new_A[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < count; i++) {
            delete[] new_A[i];
        }
        delete[] new_A;
        new_A = nullptr;
    }
    else {
        cout << "Все строки были удалены" << endl;
        delete[] new_A;
        new_A = nullptr;
    }

    return 0;
}