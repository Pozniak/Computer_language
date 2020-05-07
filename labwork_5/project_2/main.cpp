#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const int size_dec = 10, size_oct = 7, size_hex = 15;
    int i = 0, n;
    do {
        cout<<"Выберите систему счисления (0-выход, 1-восьмеричная, 2-десятичная, 3-шестнадцатеричная): ";
        cin>>n;
        if (n > 3) {
            cout<<"Незаконная операция\n";
        } else if (n >0) {
            if (n==1) {
                cout << "Таблица умножения для восьмеричной системы счисления:" << endl;
                for(i = 0; i < size_oct*size_oct; i++) {
                    cout << setw(3) << oct << (i/size_oct + 1)*(i%size_oct + 1);
                    if((i + 1)%size_oct == 0)            cout << endl;
                }
            }
            if (n==2) {
                cout << endl << "Таблица умножения для десятичной системы счисления:" << endl;
                for(i = 0; i < size_dec*size_dec; i++) {
                    cout << setw(3) << dec << (i/size_dec + 1)*(i%size_dec + 1);
                    if((i + 1)%size_dec == 0)            cout << endl;
                }
            }
            if (n==3) {
                cout << endl << "Таблица умножения для шестнадцатеричной системы счисления:" << endl;
                for(i = 0; i < size_hex*size_hex; i++) {
                    cout << setw(3) << hex << (i/size_hex + 1)*(i%size_hex+ 1);
                    if((i + 1)%size_hex == 0)            cout << endl;
                }
            }
        }
    } while (n!=0);
    return 0;
}
