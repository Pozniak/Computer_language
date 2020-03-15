#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int number,divis, i;
    cout << "//Проверка на простое число//\n";
    cout << "Введите число: ";
    cin >> number;
    cout << "Простое?\n";
    if (number==0) {
        cout << "Невозможно найти\n";
        return 1;
    }
    if (number==1) {
        cout << "Да\n";
        return 0;
    }
    divis=0;
    for (i=2 ; i<=number; i++) {
        if(number%i==0) {
            divis++;
        }
    }
    if (divis==1) {
        cout << "Да\n";
    } else {
        cout << "Нет\n";
    }
    return 0;
}
