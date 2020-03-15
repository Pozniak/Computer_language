#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int N,m;
    int x,i;
    double R,S;
    S=0;
    i=0;
    m=1;
    cout << "Введите длинну последовательности N: ";
    cin >> N;
    if (N!=i) {
        if (N==1) {
            cout << "Невозможно определить среднее арифмтетическое от одного числа, т.к. искомое число ей и является\n";
        } else {
            cout << "Введите последовательность чисел:\n";

        while(i<N) {
            cout << m;
            cout << ")";
            cin >> x;
            S=S+x;
            i++;
            m=m+1;
        }

        R=S/N;
        cout << "Среднее арифметическое: ";
        cout << R << endl;
        }
    } else {
        cout << "Нулевой последовательности не существует\n";
    }
    return 0;
}
