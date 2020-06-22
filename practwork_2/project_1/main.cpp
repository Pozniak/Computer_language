#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    time_t t = time(NULL);
    tm * ptm;
    ptm = localtime(&t);
    char buf[80];
    strftime(buf, 80, "%c", ptm);
    cout << buf << endl;
    return 0;
}