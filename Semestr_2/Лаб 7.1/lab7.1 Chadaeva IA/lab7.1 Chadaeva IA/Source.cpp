#include <iostream>
#include <cstring>
using namespace std;

int min_element(int n, int a[])
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int min_element(char str[])
{
    int min_len = strlen(str);
    int current = 0;

    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            current++;
        }
        else
        {
            if (current > 0 && current < min_len)
            {
                min_len = current;
            }
            current = 0;
        }
    }
    return min_len;
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");
    const int N = 10;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 200 - 100;
    }

    cout << "Массив: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << "Минимальный элемент массива: " << min_element(N, arr) << endl;

    char text[256];
    cout << "Введите строку: ";
    cin.getline(text, 256);

    cout << "Длина самого короткого слова: " << min_element(text) << endl;

    return 0;
}