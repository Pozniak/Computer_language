#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int key,search;
    cout << "Введите ключ: ";
    cin >> key;
    if (key!=0) {
        do {
            cout << "Введите число: ";
            cin >> search;
            if (search==key) {
                break;
            } else {
                cout << "Число неидентично ключу\n";
            }
        } while(search!=0);
        if (search!=0) {
            cout << "Ключ найден!\n";
        } else {
            cout << "Ключ не найден!\n";
        }
    } else {
        cout << "Невозможно найти\n";
    }
    return 0;
}
