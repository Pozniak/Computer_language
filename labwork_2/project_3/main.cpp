#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int S,x,m;
    S=0;
    m=1;
    cout << "Введите последовательность целых чисел:\n";
    do {
        cout << m;
        cout << ")";
        cin >> x;
        m=m+1;
        if (x>0) {
            S=S+x;
        }
    } while(x!=0);
    cout << "Значение суммы: ";
    cout << S << endl;
    return 0;
}
