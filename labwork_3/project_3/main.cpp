#include <iostream>
using namespace std;
void standardization(double *m1, int k)
{
    double x1=0, x2=1, r, n;
    double *m=new double [k];
    for (int i=0; i<k; i++)  {
        cout<< "Введите число: ";
        cin>>r;
        m[i]=r/1000;
        if (m[i]>x1)
            x1=m[i];
        if(m[i]<x2)
            x2=m[i];
    }
    for(int i=0; i<k; i++)  {
        n=(m[i]-x2)/(x1-x2);
        cout<<"Нормированное значение: "<<n<<endl;
        m[i]=n;
    }
    cout<<"Значение массива: [";
    for (int i=0; i<k; i++)  {
        cout<<m[i]<<" "<<" ";
    }
    cout<<"] "<<endl;
        delete[ ] m;
}
int main()
{
    int N;
    cout<<"Введите количество элементов массива: ";
    cin>>N;
    double* a=new double [N];
    standardization(a, N);
    delete[ ] a;
    return 0;
}
