#include <iostream>
#include <clocale>

using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите число Фибоначчи: ";
	cin >> n;

	cout << n << "-e число в последовательности Фибоначчи = " << fib(n);

	return 0;
}