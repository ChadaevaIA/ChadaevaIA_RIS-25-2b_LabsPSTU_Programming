#include <iostream>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");
    const int n = 100;
    int A[n];
    int temp;

    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100 - 50;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    int min = A[0], max = A[0];
    int imin = 0, imax = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            imin = i;
        }
        if (A[i] > max) {
            max = A[i];
            imax = i;
        }
    }

    temp = A[imin];
    A[imin] = A[imax];
    A[imax] = temp;

    cout << "Минимальный элемент массива: " << min << endl
        << "Максимальный элемент массива: " << max << endl << endl;

    cout << "Массив после перестановки мин. и макс.: ";

    for (int i = 0; i < n; i++) {
        if (i == imin || i == imax) {
            cout << "\033[33m" << A[i] << "\033[0m" << " ";  
        }
        else {
            cout << A[i] << " ";
        }
    }

    cout << endl << endl;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    double avg = sum / n;
    double limit = avg * 1.1;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] <= limit) {
            A[j] = A[i];
            j++;
        }
    }

    cout << "Итоговый массив: ";
    for (int i = 0; i < j; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
