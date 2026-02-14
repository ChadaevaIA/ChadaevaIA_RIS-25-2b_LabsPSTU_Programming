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

	for (int i = 0; i < n/2; i++) {

		temp = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = temp;
	}

	cout << endl << "Перевернутый массив: ";

	for (int i = 0; i < n; i++) {
		
		cout << A[i] << " ";
	}

	return 0;
}