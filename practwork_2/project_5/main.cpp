#include <stdint.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const uint64_t ODD = 0x1;

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
    uint64_t next_bit_setted = 0b10;
    uint64_t result = 0;
    cout << "Найденные числа\n";
    for (unsigned int i = 0; i < sizeof(uint64_t) * 8 - 1; i++) {
        result = next_bit_setted | ODD;
        if (is_prime(result)) {
            cout << "---------------------------\n";
            cout << "Десятичный вид: " << result << endl;
            cout << "Шестнадцатеричный вид: " << hex << result << endl << dec;
        }
        next_bit_setted <<= 1;
    }
    cout << "---------------------------\n";
    return 0;
}