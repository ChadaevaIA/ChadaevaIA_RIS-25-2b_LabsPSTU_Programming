#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int n = 100;

struct Film {
    char name[n];
    char director[n];
    char country[n];
    double profit;
};

// формирование файла
void createFile(const char* filename, int count)
{
    ofstream fout(filename);

    if (!fout)
    {
        cout << "Ошибка открытия файла для записи\n";
        return;
    }

    Film f;

    for (int i = 0; i < count; i++)
    {
        cout << "\nФильм № " << i + 1 << endl;

        cin.ignore();

        cout << "Название фильма: ";
        cin.getline(f.name, 100);

        cout << "Режиссер фильма(Фамилия и имя): ";
        cin.getline(f.director, 100);

        cout << "Страна: ";
        cin.getline(f.country, 100);

        cout << "Прибыль(в млн руб.): ";
        cin >> f.profit;

        fout << f.name << endl;
        fout << f.director << endl;
        fout << f.country << endl;
        fout << f.profit << endl;
    }

    fout.close();
}

// печать файла
void printFile(const char* filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Ошибка открытия файла\n";
        return;
    }

    Film f;

    cout << "\nСодержимое файла:\n";

    while (fin.getline(f.name, 100))
    {
        fin.getline(f.director, 100);
        fin.getline(f.country, 100);
        fin >> f.profit;
        fin.ignore();

        cout << "\nНазвание фильма: " << f.name << endl;
        cout << "Режиссер фильма(Фамилия и имя): " << f.director << endl;
        cout << "Страна: " << f.country << endl;
        cout << "Прибыль(в млн руб.): " << f.profit << endl;
    }

    fin.close();
}

// удаление двух элементов с конца
void deleteLastTwo(const char* filename)
{
    ifstream fin(filename);
    ofstream fout("temp.txt");

    if (!fin || !fout)
    {
        cout << "Ошибка открытия файла\n";
        return;
    }

    Film films[100];
    int count = 0;

    while (fin.getline(films[count].name, 100))
    {
        fin.getline(films[count].director, 100);
        fin.getline(films[count].country, 100);
        fin >> films[count].profit;
        fin.ignore();
        count++;
    }

    fin.close();

    if (count < 2)
    {
        cout << "Недостаточно элементов для удаления\n";
        return;
    }

    count -= 2;

    for (int i = 0; i < count; i++)
    {
        fout << films[i].name << endl;
        fout << films[i].director << endl;
        fout << films[i].country << endl;
        fout << films[i].profit << endl;
    }

    fout.close();

    remove(filename);
    rename("temp.txt", filename);
}

// поиск фильма
bool findFilm(Film films[], int count, const char* title, int& pos)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(films[i].name, title) == 0)
        {
            pos = i;
            return true;
        }
    }
    return false;
}

// добавление после указанного фильма
void addAfter(const char* filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Ошибка открытия файла\n";
        return;
    }

    Film films[100];
    int count = 0;

    while (fin.getline(films[count].name, 100))
    {
        fin.getline(films[count].director, 100);
        fin.getline(films[count].country, 100);
        fin >> films[count].profit;
        fin.ignore();
        count++;
    }

    fin.close();

    char title[100];

    cout << "\nВведите название фильма после которого добавить: ";
    cin.ignore();
    cin.getline(title, 100);

    int pos;

    if (!findFilm(films, count, title, pos))
    {
        cout << "Фильм не найден\n";
        return;
    }

    Film newFilm;

    cout << "\nВведите данные нового фильма\n";

    cout << "Название фильма: ";
    cin.getline(newFilm.name, 100);

    cout << "Режиссер фильма(Фамилия и имя): ";
    cin.getline(newFilm.director, 100);

    cout << "Страна: ";
    cin.getline(newFilm.country, 100);

    cout << "Прибыль(в млн руб.): ";
    cin >> newFilm.profit;

    for (int i = count; i > pos + 1; i--)
    {
        films[i] = films[i - 1];
    }

    films[pos + 1] = newFilm;
    count++;

    ofstream fout(filename);

    for (int i = 0; i < count; i++)
    {
        fout << films[i].name << endl;
        fout << films[i].director << endl;
        fout << films[i].country << endl;
        fout << films[i].profit << endl;
    }

    fout.close();
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");

    const char* file = "films.txt";

    int n;

    cout << "Количество фильмов: ";
    cin >> n;

    createFile(file, n);

    printFile(file);

    deleteLastTwo(file);

    cout << "\nПосле удаления двух элементов:\n";
    printFile(file);

    addAfter(file);

    cout << "\nПосле добавления:\n";
    printFile(file);

    return 0;
}