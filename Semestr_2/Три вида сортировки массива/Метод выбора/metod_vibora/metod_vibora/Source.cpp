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

        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        cout << "Шаг " << i + 1 << ": ";

        cout << "[ ";
        for (int k = 0; k <= i; k++) {
            cout << A[k] << " ";
        }
        cout << "] ";

        for (int k = i + 1; k < n; k++) {
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
