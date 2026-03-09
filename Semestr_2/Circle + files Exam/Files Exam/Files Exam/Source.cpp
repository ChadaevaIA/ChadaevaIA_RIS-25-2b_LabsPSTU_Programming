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
        cout << "Ошибка открытия F1" << endl;
        return 1;
    }

    const int n = 1000;

    int numbers[n];
    string words[n];
    int count = 0;

    string line;
    string word = "";

    int wordNumber = 0;
    int maxConsonants = 0;

    while (getline(F1, line))
    {
        int wordCount = 0;
        word = "";

        for (int i = 0; i <= line.length(); i++)
        {
            if (i < line.length() && line[i] != ' ')
            {
                word += line[i];
            }
            else
            {
                if (!word.empty())
                {
                    wordCount++;
                    wordNumber++;

                    int conCount = 0;

                    for (int j = 0; j < word.length(); j++)
                    {
                        if (isConsonant(word[j]))
                        {
                            conCount++;
                        }
                    }

                    if (conCount > maxConsonants)
                    {
                        maxConsonants = conCount;
                        count = 0;

                        numbers[count] = wordNumber;
                        words[count] = word;
                        count++;
                    }
                    else if (conCount == maxConsonants)
                    {
                        numbers[count] = wordNumber;
                        words[count] = word;
                        count++;
                    }

                    word = "";
                }
            }
        }

        if (wordCount > 2)
        {
            F2 << line << endl;
        }
    }

    cout << "Максимальное количество согласных: " << maxConsonants << endl;
    cout << "Слова с таким количеством согласных:\n";

    for (int i = 0; i < count; i++)
    {
        cout << "Номер слова: " << numbers[i] << "  Слово: " << words[i] << endl;
    }

    F1.close();
    F2.close();

    return 0;
}