#include <iostream>
using namespace std;
template <typename T1, typename T2>
class DoubleBox
{
    private:
    T1 x;
    T2 y;
public:
    DoubleBox(){x = 0;y = 0;}
    DoubleBox(T1 valueX, T2 valueY = 0):x(valueX),y(valueY) {}
    T1 GetX() {return x;}
    T2 GetY() {return y;}
    void SetX(T1 valueX){x = valueX;}
    void SetY(T2 valueY){y = valueY;}
    void SetGlobal(T1 valueX, T2 valueY) {
    x = valueX;
    y = valueY;
    }
    void print(){
        cout << endl << "Вывод из конструктора: " << endl;
        cout << "x = " << x << endl << "y = " << y << endl << endl;}
};

int main()
{
    DoubleBox<int, double> Box;
    cout << "Get x: " << Box.GetX() << endl;
    cout << "Get y: " << Box.GetY() << endl;
    Box.SetX(5);
    Box.SetY(2.253);
    Box.print();
    cout << "Get x: " << Box.GetX() << endl;
    cout << "Get y: " << Box.GetY() << endl;
    Box.SetGlobal(10,8.00445);
    Box.print();
    return 0;
}