#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    system("cls");

    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    string result;
    string word;
    int length = text.length();

    for (int i = 0; i <= length; i++) {

        if (i < length && text[i] != ' ') {
            word += text[i];
        }
        else {

            if (!word.empty()) {

                if (word[0] >= '0' && word[0] <= '9') {
                    result += word + " ";
                }
            }
            word = "";
        }
    }

    string words[100];
    int wordCount = 0;
    string temp = "";

    for (int i = 0; i < result.length(); i++) {
        if (result[i] != ' ') {
            temp += result[i];
        }
        else {
            words[wordCount] = temp;
            wordCount++;
            temp = "";
        }
    }
    if (!temp.empty()) {
        words[wordCount] = temp;
        wordCount++;
    }

    if (wordCount == 0) {
        cout << "Слов, начинающихся с цифры нет." << endl;
    }
    else
    {
        for (int i = 0; i < wordCount - 1; i++) {
            for (int j = 0; j < wordCount - i - 1; j++) {
                if (words[j] < words[j + 1]) {
                    string tempWord = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = tempWord;
                }
            }
        }

        cout << "Слова, начинающиеся с цифры (по убыванию):" << endl;
        for (int i = 0; i < wordCount; i++) {
            cout << words[i] << endl;
        }
    }

    return 0;
}