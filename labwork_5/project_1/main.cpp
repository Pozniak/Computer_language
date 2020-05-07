#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i[10];
    for (int n=0; n<10 ; n++) {
        cout << "Введите число: ";
        cin >> i[n];
        cout << setw(5) << oct << i[n] << setw(5) << dec << i[n] << setw(5) << hex << i[n] << endl;
    }
    return 0;
}
