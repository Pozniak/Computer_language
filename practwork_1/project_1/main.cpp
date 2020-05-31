#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int quantity;
    string a = "а";
    string ov = "ов";
    string name = "верблюд";
    cout << "Для выхода из программы введите - 0\n";
    while(quantity != 0) {
        cout << "Введите число от 1 до 100: ";
        cin >> quantity;
        if (quantity == 0) cout<<"Производится выход из программы."<<endl;
        else if (quantity < 0 || quantity > 100) cout<<"Число вне диапозона."<<endl;
        else if (quantity % 10 == 1 && (quantity < 11 || quantity > 14)) cout << "В караване был " << quantity << " " << name << endl;
        else if ((quantity % 10 >= 2 && quantity % 10 <= 4) && (quantity < 11 || quantity > 14)) cout << "В караване было " << quantity << " " << name + a << endl;
        else if ((quantity % 10 >= 5 && quantity % 10 <= 9) || quantity % 10 == 0 || (quantity >= 11 || quantity <= 14)) cout << "В караване было " << quantity << " " << name + ov << endl;
    }
    return 0;
}
