#include <iostream>
using namespace std;
void standardization(double* m, int k)
{
    double x1=0, x2=1, r, n;
    for (int i=0; i<k; i++) {
        cout<< "Введите число: ";
        cin>>r;
        m[i]=r/1000;
        if (m[i]>x1)
            x1=m[i];
        if(m[i]<x2)
            x2=m[i];
    }
    for(int i=0; i<k; i++) {
        n=(m[i]-x2)/(x1-x2);
        cout<<"Нормированное значение: "<<n<<endl;
    }
}
int main()
{
    int SIZE;
    cout<<"Введите количество элементов массива: ";
    cin>>SIZE;
    double* a=new double [SIZE];
    standardization(a, SIZE);
    delete[] a;
    return 0;
}
