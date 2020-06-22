#include <iostream>
using namespace std;
template< class T >
void insertSort(T* a, int size) 
{
    T tmp;
    for (int i = 1, j; i < size; ++i)
    {
        tmp = a[i]; 
        for (j = i - 1; j >= 0 && a[j] > tmp; --j)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}
int main(int argc, char **argv)
{
	int a[100], size_int;
    cout << "Введите кол-во элементов(int): ";
    cin >> size_int;
    for(int i = 0; i < size_int; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> a[i];
    }
    insertSort(a, size_int);
       for(int i = 0; i < size_int; i++) {
        cout << a[i] << " ";
    }
    double b[100], size_double;
    cout << "\nВведите кол-во элементов(double): ";
    cin >> size_double;
    for(int i = 0; i < size_double; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> b[i];
    }
    insertSort(b, size_double);
       for(int i = 0; i < size_double; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}