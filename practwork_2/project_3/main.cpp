#include <stdint.h>
#include <random>
#include <ctime>
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int count = 3;

bool is_prime(uint64_t);

uint64_t generator_prime(uint64_t min, uint64_t max)
{
    random_device rd;
    static mt19937_64 gen(rd());
    uint64_t result = 0;
    do {
        result = gen();
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
    for (uint64_t i = 3; i <= (uint64_t)sqrt(n); i+= 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    for (int i = 0; i < count; i++) {
        auto t1 = std::chrono::system_clock::now();
        cout << "Число "<< generator_prime(0, 0xFFFFFFFFFFFFFFFF);
        cout << " сгенерировано за " << chrono::duration<double>(chrono::system_clock::now() - t1).count() << " секунд" << endl;
    }
    return 0;
}