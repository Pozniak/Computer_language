#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream fin;
    string text;
    fin.open("text.txt");
    while(getline(fin,text)) {
        string search;
        string replace;
        cout << "Введите слово, которое хотите заменять: ";
        cin >> search;
        cout << "Введите слово, на которое хотите заменять: ";
        cin >> replace;
        for (unsigned int i = 0; i < text.length(); i++) {
            if (text.substr(i, search.length()) == search)
                text.replace(i, search.length(), replace);
        }
        cout << text << endl;
    };
    fin.close();
    return 0;
}