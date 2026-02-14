#include <iostream>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");
    const int n = 10;
    int A[n];
    int temp;

    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 - 50;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }

        cout << "Шаг " << i + 1 << ": ";

        cout << "[ ";
        for (int k = 0; k < n - i - 1; k++) {
            cout << A[k] << " ";
        }
        cout << "] ";

        for (int k = n - i - 1; k < n; k++) {
            cout << A[k] << " ";
        }

        cout << endl << endl;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
