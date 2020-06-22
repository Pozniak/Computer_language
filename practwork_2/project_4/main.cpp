#include <stdint.h>
#include <random>
#include <ctime>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int size = 1000;

bool is_prime(size_t);

size_t generator_prime()
{
    random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<size_t> a(0, 0xFFFFFFFF);
    size_t result = 0;
    do {
        result = a(gen);
    } while (!is_prime(result));

    return result;
}

bool is_prime(size_t n)
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
    for (size_t i = 3; i <= (size_t)sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<size_t> arr(size);
    std::generate(arr.begin(), arr.end(), generator_prime);
    std::sort(arr.begin(), arr.end());
    cout << "Минимальное простое число: " <<  arr[0] << endl;
    cout << "Максимальное простое число: " << arr[arr.size() - 1] << endl;
    return 0;
}