#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    char name_file1[15];
    cout << "Введите имя первого файла: ";
    cin.getline(name_file1,15);
    ifstream file1;
    file1.open(name_file1);
    if(file1.is_open()) {
        cout << "Первый файл найден" << endl;
        char name_file2[15];
        cout << "Введите имя второго файла: ";
        cin.getline(name_file2,15);
        ifstream file2;
        ofstream file3;
        file2.open(name_file2);
        if(file2.is_open()) {
            cout << "Второй файл найден" << endl;
            file3.open(name_file2,ios::app);
        } else {
            cout << "Файл не найден. Будет создан файл с именем: " << name_file2 << endl;
            file2.close();
            file3.open(name_file2,ios::app);
        }
        cout << "Выполняется обработка...\nВсё готова!" << endl;
        string str;
        while(getline(file1, str)) {
            file3 << str;
        }
        file3.close();
    } else {
        cout << "Файл не найден\nЗавершение работы." << endl;
    }
    file1.close();
    return 0;
}
