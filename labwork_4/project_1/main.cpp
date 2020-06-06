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
    String():value(new char[1] {}),len(0) {};

    //Конструктор копирования
    String(const String& s);

    //Деструктор
    ~String()
    {
        delete[] value;
    }

    //Перегруженный оператор<<
    friend ostream& operator<<(ostream& o, const String & s);
};
ostream& operator<<(ostream& outputStream, const String & s)
{
    return outputStream << s.value;
}
