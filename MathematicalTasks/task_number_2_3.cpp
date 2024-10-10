#include <iostream>

//
// Created by O.Demnychenko on 28.07.2024.
//
int gcd(int const a, int const b)
{
    auto result = b == 0 ? a : gcd(b, a % b);
    return result;
}

int lcm(int const a, int const b)
{
    int h = gcd(a, b);
    return h ? (a * (b / h)) : 0 ;
}
int main()
{
    std::cout << lcm(3, 20) << std::endl;
    return 0;
}