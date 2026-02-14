#include <iostream>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");
    const int n = 10;
    int A[n];
    int temp, j;

    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 - 50;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    for (int i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;

        cout << "Шаг " << i << ": ";

        cout << "[ ";
        for (int k = 0; k < i; k++) {
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