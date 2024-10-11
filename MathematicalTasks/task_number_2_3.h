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
static void task_number_2_3()
{
    std::cout << lcm(3, 20) << std::endl;
}