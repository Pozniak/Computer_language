#include <iostream>
#include <string>
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

//Деструктор
    ~String()
    {
        cout << "Вызов деструктора" << endl;
        delete[] value;
    }

//Перегруженный оператор<<
    friend ostream& operator<<(ostream& o, const String & s);
};
ostream& operator<<(ostream& outputStream, const String & s)
{
    return outputStream << s.value;
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
    return 0;
}
