#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <fstream>
using namespace std;
void findPass(string pass, const string& hash)
{
    static mutex mtx;
    mtx.lock();
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    mtx.unlock();
    do {
        mtx.lock();
        string newHash = crypt_r(pass.data(),hashHead.data(),pCryptData);
        mtx.unlock();
        if (newHash == hash) {
            mtx.lock();
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            mtx.unlock();
            break;
        }
    } while (next_permutation( pass.begin(), pass.end() ) );
    mtx.lock();
    delete pCryptData;
    mtx.unlock();
}
int main(int argc, char *argv[])
{
    cout << "Hardware_concurrency: " << thread::hardware_concurrency() << endl;
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
            if (fin >> text){
            count++;
            cout << count << "| ";
            thread th_2 (findPass, "123456789", text);
            th_2.join();}
            count++;
        }
    }
    fin.close();
    return 0;
}
