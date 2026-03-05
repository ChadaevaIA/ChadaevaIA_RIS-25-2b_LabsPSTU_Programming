#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
	const int n = 10, m = 10;

	int A[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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

    for (int i = 0; i < m - 1; i++) {
        int min_a = A[1][i];
        int min_i = i;
        for (int j = i + 1; j < m; j++) {
            if (A[1][j] < min_a)
            {
                min_a = A[1][j];
                min_i = j;
            }
        }
        for (int k = 0; k < n; k++) {
            int temp = A[k][i];
            A[k][i] = A[k][min_i];
            A[k][min_i] = temp;
        }
    }

    cout << "Итоговый массив:" << endl;

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

	return 0;
}