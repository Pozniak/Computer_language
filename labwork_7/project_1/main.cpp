#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <thread>
#include <fstream>
using namespace std;

void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}

int main(int argc, char *argv[])
{
    string text;
    ifstream fin("Hash_8.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        int count=1;
        while (fin >> text) {
            cout << count << "| ";
            thread th_1 (findPass, "123456789", text);
            th_1.join();
            count++;
        }
    }
    fin.close();
    return 0;
}
