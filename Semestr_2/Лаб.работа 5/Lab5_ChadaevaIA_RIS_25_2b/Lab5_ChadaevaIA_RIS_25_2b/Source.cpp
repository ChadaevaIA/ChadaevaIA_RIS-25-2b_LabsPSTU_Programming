#include <iostream>
#include <clocale>
#include <iomanip> 

using namespace std;

const int n = 10;
const int m = 10;
int findMaxAndShift(int A[n][m], int row) {
    int max = A[row][0];
    for (int i = row; i <= row; i++) {
        for (int j = 0; j < m; j++) {
            if (max < A[i][j]) {
                max = A[i][j];
            }
        }
    }
    int k = max % m;
    int temp[m];
    for (int i = 0; i < n; i++) {   
     
        for (int j = 0; j < m; j++) {
            temp[(j + k) % m] = A[i][j];
        }

       
        for (int j = 0; j < m; j++) {
            A[i][j] = temp[j];
        }
    }

    return max;
}

int main() {

    setlocale(LC_ALL, "ru");

    int A[n][m];
    int row;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = rand() % 200 - 100;
        }
    }

    cout << "Исходный массив:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] >= 0) {
                cout << " " << setw(3) << A[i][j] << " ";  
            }
            else {
                cout << setw(4) << A[i][j] << " ";  
            }
        }
        cout << endl << endl;
    }
    cout << endl << endl << "Введите номер строки: ";
    
    cin >> row;
    if (row < 1 || row > n) {
        cout << "Размер массива = " << n << " x " << m << ". Введите номер строки в диапазоне данного размера." << endl;
    }
    else 
    {
        cout << "Максимальный элемент " << row << " строки = " << findMaxAndShift(A, row - 1) << endl << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] >= 0) {
                cout << " " << setw(3) << A[i][j] << " ";
            }
            else {
                cout << setw(4) << A[i][j] << " ";
            }
        }
        cout << endl << endl;
    }
    cout << endl << endl;
    return 0;
}
