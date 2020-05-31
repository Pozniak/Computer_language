#include <iostream>
#include <string>
#include <locale>
using namespace std;

std::wstring encrypt(const std::wstring& text, const int key)
{
    int changeskey;
    wstring changestext = text;
    wstring shifr;
    if (key > 32) changeskey = key % 32;
    else changeskey = key;
    for (wchar_t & wc: changestext) {
        if ((wc - changeskey) < L'А')           
            shifr += wc - changeskey + 32;
        else shifr += wc - changeskey;
    }
    return shifr;
}

int main(int argc, char **argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    wstring text;
    wstring textup = L"";
    wcout << L"Введите текст: ";
    getline(wcin, text);
    int key;
    wcout << L"Введите ключ: ";
    wcin >> key;
    for(wchar_t & wc: text) {
        if ((wc >= L'а' && wc <= L'я') ||
            (wc >= L'А' && wc <= L'Я' )) {
            wc = toupper(wc,loc);
            textup += wc;
        }
    }
    wcout<<L"Зашифрованный текст: "<<encrypt(textup, key)<<endl;
    return 0;
}
