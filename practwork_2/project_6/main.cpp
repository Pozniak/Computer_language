#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int bit_size = 3;
bool has_bit_length(unsigned int a)
{
    int count = a & 0x1;
    while (a) {
        (a >>= 1) & 0x1 ? count++ : 0;
        if (count > bit_size) {
            break;
        }
    }
    return count == 3;
}
bool is_prime(uint64_t n)
{
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if ((n & 1) == 0) {
        return false;
    }
    for (uint64_t i = 3; i <= (uint64_t)sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    cout << "Найденные числа\n";
    for (unsigned int result = 0x80000001; result < 0xFFFFFFFF; result+= 2) {
        if (has_bit_length(result)) {
            if (is_prime(result)) {
                cout << "-------------------------------\n";
                cout << "Десятичный вид: " << result << endl;
                cout << "Шестнадцатеричный вид: " << hex << result << endl << dec;
            }
        }
    }
    cout << "-------------------------------\n";
    return 0;
}