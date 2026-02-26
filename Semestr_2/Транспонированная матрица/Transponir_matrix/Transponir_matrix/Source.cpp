#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	int const n = 10;
	int const m = 10;
	int A[n][m];

	if (n != m) {
		cout << "Введите размеры квадратной матрицы (n == m)";
	}
	else

	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = rand() % 200-100;
			}
		}

		cout << "Исходный массив: " << endl << endl;
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

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < m; j++) {
				int temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
			}
		}
		cout << "Итоговый массив: " << endl << endl;

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
	}

	return 0;
}