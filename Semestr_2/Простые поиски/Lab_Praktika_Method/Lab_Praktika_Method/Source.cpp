#include <iostream>
#include <clocale>
#include <string>

using namespace std;

int LinMethod(int arr[], int key, const int n)
{
	int position = -1;  

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key) {
			position = i + 1;
		}
	}

	return position;  
}

int BinMethod(int arr[], int key, const int n) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == key) {
			return mid + 1;
		}
		else {
			if (arr[mid] < key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return -1;
}

int InterMethod(int arr[], int key, int n) 
{
	int left = 0;
	int right = n - 1;
	while (left <= right) 
	{
		int mid = left + (((key - arr[left]) * (right - left)) / (arr[right] - arr[left]));
		if (arr[mid] == key) 
		{
			return mid + 1;
		}
		else 
		{
			if (arr[mid] < key) {
			
				left = mid + 1;
			}
			else 
			{
				right = mid - 1;
			}
		}
		
	}
	return -1;
}

// Аналитич. способ
void interAnalyt() {
	cout << "\n--- Аналитическое объяснение интерполяционного поиска ---" << endl;
	cout << "Интерполяционный поиск определяет предполагаемую позицию элемента по формуле:" << endl;
	cout << "mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left])" << endl;

	cout << "Смысл формулы в том, что положение элемента оценивается с учетом значений на границах массива." << endl;
	cout << "Предполагается, что данные распределены примерно равномерно." << endl;

	cout << "Формула получена из уравнения прямой, проходящей через две точки:" << endl;
	cout << "(left, arr[left]) и (right, arr[right])." << endl;

	cout << "Используется зависимость между индексами и значениями элементов массива." << endl;
	cout << "Подставляя значение key в это уравнение, можно вычислить индекс mid," << endl;
	cout << "где с наибольшей вероятностью находится искомый элемент.\n" << endl;
}

void SubstrMethod(const string& text, const string& pattern)
{
	int n = text.length();
	int m = pattern.length();

	if (m == 0)
	{
		cout << "Шаблон пуст!" << endl;
		return;
	}

	bool found = false;

	for (int i = 0; i <= n - m; i++)
	{
		cout << "Шаг " << i + 1 << ": Позиция в тексте: " << i << endl;
		cout << "Текст: " << text << endl;

		cout << "Шаблон: ";
		for (int k = 0; k < i; k++)
		{
			cout << " ";
		}
		cout << pattern << endl;

		bool match = true;

		for (int j = 0; j < m; j++)
		{
			cout << "  text[" << i + j << "] = '" << text[i + j]
				<< "' и pattern[" << j << "] = '" << pattern[j] << "'";

			if (text[i + j] != pattern[j])
			{
				cout << " - Не совпадают!" << endl;
				match = false;
				break;
			}
			else
			{
				cout << " - Совпадают!" << endl;
			}
		}

		if (match)
		{
			cout << ">>> Найдено полное совпадение на позиции " << i << endl;
			found = true;
		}
		cout << endl;
	}

	if (!found)
	{
		cout << "Подстрока не найдена в тексте!" << endl;
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	const int n = 10;
	int arr[n];
	int key;
	int lin, bin, inter;
	int temp;

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 200 - 100;
	}

	for (int i = 0; i < n - 1; i++) {

		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "Введите значение: ";
	cin >> key;
	lin = LinMethod(arr, key, n);
	bin = BinMethod(arr, key, n);
	inter = InterMethod(arr, key, n);

	cout << "Линейный метод: " << endl;
	if (lin == -1) {
		cout << "Элемент не найден" << endl;;
	}
	else {
		cout << "Элемент найден в позиции: " << lin << endl; 
	}

	cout << "Бинарный метод: " << endl;
	if (bin == -1) {
		cout << "Элемент не найден" << endl;
	}
	else {
		cout << "Элемент найден в позиции: " << bin << endl;
	}

	cout << "Интерполяционный метод: " << endl;
	if (inter == -1) {
		cout << "Элемент не найден" << endl;
	}
	else {
		cout << "Элемент найден в позиции: " << inter << endl;
	}

	interAnalyt();

	cout << "Прямой поиск подстроки: " << endl;
	string text, pattern;
	cin.ignore();
	cout << "Введите строку: ";
	getline(cin, text);

	cout << "Введите подстроку для поиска: ";
	getline(cin, pattern);

	if (text.empty())
	{
		cout << "Строка не может быть пустой!" << endl;
		return 1;
	}

	if (pattern.empty())
	{
		cout << "Подстрока не может быть пустой!" << endl;
		return 1;
	}

	if (text.length() < pattern.length())
	{
		cout << "Подстрока не может быть длиннее строки!" << endl;
		return 1;
	}

	SubstrMethod(text, pattern);

	return 0;
}