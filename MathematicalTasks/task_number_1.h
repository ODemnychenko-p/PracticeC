//
// Created by O.Demnychenko on 28.07.2024.
//

#include <iostream>
#include <algorithm>

void CalculateSum()
{
    int num = 0;
    int sum = 0;
    std::cin >> num;

    if(num)
    {
        for(size_t i = 0; i < num; i++)
        {
            if(i % 3 || i % 5)
            {
                sum += i;
            }
        }
        std::cout << "Summ of natural numbers multiple by 3 and 5 is: " << sum << std::endl;
    }
}

static void task_number_1()
{
    CalculateSum();
}