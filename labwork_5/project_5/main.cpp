#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char name_file1[15];
    cout << "Введите имя первого файла: ";
    cin.getline(name_file1,15);
    ifstream file_1;
    file_1.open(name_file1,ios::binary);
    if(file_1.is_open()) {
        cout << "Файл подтвержден." << endl;
        double r;
        int n = 0;
        while (file_1.read((char*)&r, sizeof(r))) {
            n++;
        }
        file_1.close();
        
        char name_file2[15];
        cout << "Введите имя второго файла: ";
        cin.getline(name_file2,15);
        cout << "Количество чисел: " << n << endl;
        float * f = new float [n];
        ifstream file_2;
        file_2.open(name_file2,ios::binary);
        file_2.read((char*)f, sizeof(f));
        for (int i = 0; i < n; i++) {
            f[i]=1/f[i];
            cout << f[i] << endl;
        }
        file_2.close();
        ofstream fout;
        fout.open(name_file2,ios::binary);
        fout.write((char*)&f, sizeof(f));
        fout.close();
    } else {
        cout << "Файл не найден\nЗавершение работы." <<endl;
    }
    return 0;
}
