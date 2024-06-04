#include <iostream>
#include "..\StaticLib\Header.h"
#include <Windows.h>
using namespace std;

int main()
{
    //динамик
    HINSTANCE load;
    load = LoadLibrary(L"DinamicLib.dll");
    typedef bool (*wordintext) (string, string);
    wordintext WordInText;
    WordInText = (wordintext)GetProcAddress(load, "WordInText");


    cout << "Введите текст:";
    string text;
    cin >> text;

    cout << "Введите слово:";
    string word;
    cin >> word;

    if (WordInText(text, word))
    {
        cout << "Слово найдено!";
    }
    else
    {
        cout << "Слово не найдено.";
    }
    FreeLibrary(load);

    //статик
    cout << "Введите текст:";
    string text2;
    cin >> text2;

    cout << "Введите слово:";
    string word2;
    cin >> word2;

    if (WordInText(text2, word2))
    {
        cout << "Слово найдено!";
    }
    else
    {
        cout << "Слово не найдено.";
    }
   
}
