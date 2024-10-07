#include <iostream>

//
// Created by O.Demnychenko on 28.07.2024.
//
bool is_prime(int const num)
{
    if(num <= 3)
    {
        return  num > 1;
    }
    else if(num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    else
    {
        for(int i = 5; i * i <= num; i += 6)
        {
            if(num % i == 0 || num % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void task_4()
{
    int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;
    for (int i = limit; i > 1; i--)
    {
        if(is_prime(i))
        {
            std::cout << "Largest prime: " << i << std::endl;
            return;
        }
    }
}

void task_5()
{
    int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;
    for (int n = 2; n <= limit; n++)
    {
        if(is_prime(n) && is_prime(n + 6))
        {
            std::cout << n << "," << n + 6 << std::endl;
            //return;
        }
    }
}

int main()
{
   // task_4();
   task_5();
   return 0;
}