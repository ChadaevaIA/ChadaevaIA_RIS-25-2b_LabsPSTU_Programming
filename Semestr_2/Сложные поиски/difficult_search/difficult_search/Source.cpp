#include <iostream>
#include <clocale>
#include <string>
using namespace std;

//Алгоритм Бойера-Мура
int boyerMooreSearch(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();
    if (textLen == 0 || patternLen == 0)
    {
        return -1;
    }

    if (patternLen > textLen)
    {
        return -1;
    }

    int table[256];

    for (int i = 0; i < 256; i++)
    {
        table[i] = patternLen;
    }

    for (int i = 0; i < patternLen - 1; i++)
    {
        table[(unsigned char)pattern[i]] = patternLen - 1 - i;
    }

    int pos = patternLen - 1;

    while (pos < textLen) {
        int i = patternLen - 1; 

        while (i >= 0 && pattern[i] == text[pos - (patternLen - 1 - i)])
        {
            i--;
        }

        if (i == -1) {
            return pos - patternLen + 1; // Возвращаем индекс начала совпадения
        }

        pos += table[(unsigned char)text[pos - (patternLen - 1 - i)]];
    }

    return -1;
}

// Алгоритм Бойера-Мура-Хорспула
int horspoolSearch(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen == 0 || patternLen > textLen) 
    {
        return -1;
    }

    // Этап 1: таблица смещений
    int shiftTable[256];
    for (int i = 0; i < 256; i++) 
    {
        shiftTable[i] = patternLen;
    }

    for (int i = 0; i < patternLen - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = patternLen - 1 - i;
    }

    // Этап 2: поиск
    int pos = 0;

    while (pos <= textLen - patternLen) {
        int j = patternLen - 1;

        // Сравниваем справа налево
        while (j >= 0 && pattern[j] == text[pos + j]) {
            j--;
        }

        // Нашли совпадение
        if (j < 0) 
        {
            return pos;
        }

        // Сдвиг по последнему символу
        char lastChar = text[pos + patternLen - 1];
        pos += shiftTable[(unsigned char)lastChar];
    }

    return -1;
}

// Алгоритм Кнута-Морисса-Пратта
void pref_func(const string& pattern, int* a) {
    a[0] = 0;
    int j = 0, i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[j])
        {
            a[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0)
        {
            a[i] = 0;
            i++;
        }
        else 
        {
            j = a[j - 1];
        }
    }

}

void kmpSearch(const string& text, const string& pattern) { 
    int* a = new int[pattern.length()];
    pref_func(pattern, a);
    int i = 0, j = 0;
    while (i < text.length())
    {
        if (pattern[j] == text[i]) { 
            i++;
            j++; 
        }
        if (j == pattern.length())
        {
            cout << "Образ найден по индексу: " << i - pattern.length() + 1 << endl;
            j = a[j - 1];
        }
        else if (i < text.length() && pattern[j] != text[i])
        {
            if (j == 0) 
            {
                i++;
            }
            else 
            {
                j = a[j - 1];
            }
            
        }
        
    }
    delete[] a;
}

int main() {
    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "ru");

    string texts[] = {
        "This is a simple string",
        "Добро пожаловать в наш сад!",
        "Lisa, let me think about it"
    };
    string patterns[] = { "simp", "пожал", "think" };

    for (int i = 0; i < 3; i++) {
        cout << "\n--- НАБОР " << i + 1 << " ---\n";
        cout << "Текст: " << texts[i] << "\n";
        cout << "Поиск: " << patterns[i] << "\n";

        boyerMooreSearch(texts[i], patterns[i]);
        horspoolSearch(texts[i], patterns[i]);
        kmpSearch(texts[i], patterns[i]);
    }

    string text, pattern;
    cout << "Введите строку: ";
    cin.ignore();
    getline(cin, text);
    cout << "Введите подстроку: ";
    getline(cin, pattern);

    if (!text.empty() && !pattern.empty()) {
        cout << "\n--- РЕЗУЛЬТАТЫ ---\n";
        boyerMooreSearch(text, pattern);
        horspoolSearch(text, pattern);
        kmpSearch(text, pattern);
    }

    return 0;
}