#include <stdint.h>
#include <random>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

const int count = 3;

bool is_prime(uint64_t);

uint64_t generator_prime(uint64_t min, uint64_t max)
{
    mt19937_64 gen(clock());
    uint64_t result = 0;
    static uniform_int_distribution<uint64_t> _random(min, max);
    do {
        result = _random(gen);
    } while (!is_prime(result));

    return result;
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
    for (int i = 0; i < count; i++) {
        cout << "Число: " << generator_prime(0, 0xFFFFFFFFFFFFFFFF) << endl;
    }
    return 0;
}
