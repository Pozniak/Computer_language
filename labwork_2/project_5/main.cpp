#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int number,divis,i;
    do {
        divis=0;
        cout << "Введите число: ";
        cin >> number;
        if (number==1) cout << "Простое\n";
        else {
            for (i=2 ; i<=number; i++) {
                if(number%i==0) {
                    divis++;
                }
            }
            if (divis==1) {
                cout << "Простое\n";
            }
        }

    } while (number!=0);
    return 0;
}
