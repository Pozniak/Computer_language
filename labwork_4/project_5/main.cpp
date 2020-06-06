#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Конструктор по умолчанию
class String
{
private:
    char *value;
    int len;
public:
    string text;
    String():value(new char[1] {}),len(0)
    {
        cout << "Вызов конструктор по умолчанию" << endl;
    }

    //Конструктор копирования
    String(const String& s)
    {
        cout << "Вызов конструктор копирования" << endl;
        len=s.len;
        value = new char[len+1];
        for (int i=0; i<=len; i++)
            value[i]=s.value[i];
    }

    //Конструктор инициализации Си-строкой
    String(const char * s)
    {
        cout << "Вызов конструктор инициализации Си-строкой" << endl;
        len = strlen(s);
        value = new char[len + 1];
        strcpy(value, s);
        text=s;
    }

    //Деструктор
    ~String()
    {
        cout << "Вызов деструктора" << endl;
        delete[] value;
    }
    String& operator = (const String& equally)
    {
        len = equally.len;
        delete[] value;
        value = new char[len + 1];
        strcpy(value, equally.value);
        return *this;
    }

    //Перегруженный оператор<< и оператор>>
    friend ostream& operator<<(ostream& o, const String & s);
    friend istream& operator>>(istream &in, const String &s);
};
ostream& operator<<(ostream& outputStream, const String & s)
{
    return outputStream << s.value;
}
istream& operator>>(istream &inputStream, const String &s)
{
    return inputStream >> s.value;
}

String foo(String PT)
{
    cout << "Текст-тест: Мишин Даниил Викторович 19ПТ1" << endl;
    return PT;
}

int main()
{
    String a;
    foo(a);
    String b(a);
    String s1= String("hello");
    cout << "Текст из конструктора инициализаций Си-строк: " << s1.text << endl;
    String S, SN;
    cout << "Введите строку: ";
    cin >> S;
    SN = S;
    cout << "Вывод S: " << S << endl;
    cout << "Вывод SN: " << SN << endl;
    return 0;
}
