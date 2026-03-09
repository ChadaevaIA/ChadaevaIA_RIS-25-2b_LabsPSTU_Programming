#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isConsonant(char c)
{
    string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    return consonants.find(c) != string::npos;
}

int main()
{
    setlocale(LC_ALL, "ru");
    system("cls");

    ifstream F1("F1.txt");
    ofstream F2("F2.txt");

    if (!F1)
    {
        cout << "Ошибка открытия F1\n";
        return 1;
    }

    string line;
    string firstWord = "";
    string word = "";
    bool firstFound = false;

    while (getline(F1, line))
    {
        int i = 0;

        if (!firstFound)
        {
            while (i < line.length() && line[i] != ' ')
            {
                firstWord += line[i];
                i++;
            }
            firstFound = true;
        }

        bool found = false;
        word = "";

        for (int j = 0; j <= line.length(); j++)
        {
            if (j < line.length() && line[j] != ' ')
            {
                word += line[j];
            }
            else
            {
                if (!word.empty())
                {
                    if (word == firstWord)
                    {
                        found = true;
                    }
                    word = "";
                }
            }
        }

        if (!found)
        {
            F2 << line << endl;
        }
    }

    F1.close();
    F2.close();

    ifstream file("F2.txt");

    if (!file)
    {
        cout << "Ошибка открытия F2\n";
        return 1;
    }

    getline(file, line);

    int consonantCount = 0;

    for (int i = 0; i < line.length(); i++)
    {
        if (isConsonant(line[i]))
        {
            consonantCount++;
        }
    }

    cout << "Первая строка F2: " << line << endl;
    cout << "Количество согласных букв: " << consonantCount << endl;

    file.close();

    return 0;
}