#include <iostream>
#include <array>
using namespace std;
template <size_t N> class superlong
{
private:
    static constexpr size_t SIZE = N / 32 + (N % 32 != 0);
    std::array<uint32_t, N / 32 + (N % 32 != 0)> value;
    static std::string toHex(uint32_t u);
    std::string toHex();
public:
    superlong():value(
    {
        0
    }) {}
    superlong(const std::array<uint32_t, N / 32 + (N % 32 != 0)>& v):value(v) {}
    superlong(const std::string & s);
    superlong<N>& operator=(const superlong<N>& s);
    superlong<N> operator+(const superlong<N>& s)const;
    template <size_t X>
    friend std::ostream& operator<< (std::ostream& stream, superlong<X>& s);
};
template <size_t N>
superlong<N>::superlong(const std::string& s)
{
    value = {0};
    int i = 0;
    int invalid_argument = 0;
    size_t found=s.find_first_not_of("0123456789abcdef");
    if (found!=string::npos) {
        throw invalid_argument;
    }
    auto ptr_2 = s.end();
    auto ptr_b = s.begin();
    while (ptr_b != ptr_2) {
        auto ptr_1 = ptr_2 - 8;
        if (ptr_1 < ptr_b)
            ptr_1 = ptr_b;
        value[i] = stoul(std::string(ptr_1,ptr_2),0,16);
        ptr_2 = ptr_1;
        i++;
    }
}
template <size_t N>
superlong<N>& superlong<N>::operator=(const superlong<N>& s)
{
    value = s.value;
    return *this;
}
template <size_t N>
superlong<N> superlong<N>::operator+(const superlong<N>& s)const
{
    superlong<N> sum;
    uint32_t CF=0;
    for (size_t i=0; i<SIZE; i++) {
        sum.value[i] = CF + value[i] + s.value[i];
        if (sum.value[i]<value[i])
            CF = 1;
        else
            CF = 0;
    }
    return sum;
}
template <size_t N>
std::string superlong<N>::toHex(uint32_t u)
{
    const char d[]="0123456789abcdef";
    std::string s;
    for (int i=0; i<8; i++) {
        s = d[u & 0xf]+s;
        u >>=4;
    }
    return s;
}
template <size_t N>
std::string superlong<N>::toHex()
{
    std::string s;
    for (auto e:value)
        s=superlong<N>::toHex(e) + s;
    return s;
}
template <size_t X>
std::ostream& operator<<(std::ostream& stream, superlong<X>& s)
{
    stream<<s.toHex();
    return stream;
}
int main()
{
    try {
        const size_t SZ = 512;
        superlong<SZ> num1;
        superlong<SZ> num2("bec0ffffffffffffffffffff0000ffff000fffffffffffffeeeeeeecccc");
        superlong<SZ> num3("399fa8873c0c737abcdef87837332178798883234fff878fed732233232");
        num1 = num3;
        num1 = num1 + num2;
        std::cout<<num3<<std::endl;
        std::cout<<num2<<std::endl;
        std::cout<<num1<<std::endl;
    } catch (const int ex) {
        cout <<"Ошибка. В строке встречаются символы, не являющиеся шестнадцатеричными цифрами" << endl;
    }
    return 0;
}