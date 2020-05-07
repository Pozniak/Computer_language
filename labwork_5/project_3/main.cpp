#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int n=0;
    double s=0, a;
    cout << "Введите имя файла: ";
    char name_file[15];
    cin.getline(name_file,15);
    ifstream file;
    file.open(name_file);
    if(!file.is_open()) {
        cout << "Неверно указано имя файла!\nЗавершение работы." << endl;
    } else {
        cout << "Числа из файла:\n";
        while(file >> a) {
            cout<< a <<endl;
            n++;
            s+=a;
        }
        cout << "Количество чисел: " << n << endl;
        cout << "Сумма чисел: " << s << endl;
        cout << "Среднее арифметическое чисел: " << s/n << endl;
        file.close();
    }
    return 0;
}
