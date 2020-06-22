#include <iostream>
using namespace std;
class Rectangle
{
    int length, width, s;
public:
    Rectangle() : length (0), width(0), s(0) {};
    Rectangle(int a, int b)
    {
        length = a;
        width = b;
        s = length * width;
        cout << a << " * " << b << " = " << s << endl;
    }
    friend ostream& operator<<(ostream& outputStream,const Rectangle a);
    bool operator>(const Rectangle s);
};
ostream& operator<<(ostream& outputStream, Rectangle a)
{
    return outputStream << a.s;
}
bool Rectangle::operator>(const Rectangle s)
{
    if (this->s > s.s)
        return 1;
    return 0;
}
template< class T >
void insertSort(T* a, int size)
{
    T tmp;
    for (int i = 1, j; i < size; ++i) {
        tmp = a[i];
        for (j = i - 1; j >= 0 && a[j] > tmp; --j)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}
int main(int argc, char **argv)
{
    int n, length = 0, width = 0;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    Rectangle sort[n];
    for(int i = 0; i < n; i++) {
        cout << "Введите высоту: ";
             cin >> length;
        cout << "Введите ширину: ";
             cin >> width;
        Rectangle buf{length,width};
        sort[i] = buf;
    }
    insertSort(sort, n);
    cout << "Сортировка : ";
    for(int i = 0; i < n; i++) {
        cout << sort[i] << " | ";
    }
    cout << endl;
    return 0;
}
