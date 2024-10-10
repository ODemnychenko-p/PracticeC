//
// Created by o.demnychenko on 8/17/2024.
//

#include <iostream>
#include "task_number_1.h"

int main()
{
    /* Var 1 */
    ipv4 address(168, 192, 0, 1);
    std::cout << address << std::endl;

    ipv4 ip;
    std::cout << ip << std::endl;
    std::cin >> ip;
    if(!std::cin.fail())
    {
        std::cout << ip << std::endl;
    }

    /* Var 2 */
    std::cout << "input range: ";
    ipv4 a1, a2;
    std::cin >> a1 >> a2;
    if(a2 > a1)
    {
        for(ipv4 a = a1; a <= a2; a++)
        {
            std::cout << a << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid range!" << std::endl;

    }
    return 0;
}