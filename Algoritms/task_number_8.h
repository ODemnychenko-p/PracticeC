#include <algorithm>
#include "iostream"

void print_premutations(std::string str)
{
    std::sort(std::begin(str), std::end(str));
    do {
        std::cout << str << std::endl;
    }
    while(std::next_permutation(std::begin(str), std::end(str)));
}

void next_premutation(std::string str, std::string perm)
{
    if(str.empty())
    {
        std::cout << perm << std::endl;
    }
    else
    {
        for(size_t i = 0; i < str.size(); ++i)
        {
            next_premutation(str.substr(1), perm + str[0]);
            std::rotate(std::begin(str), std::begin(str) + 1, std::end(str));
        }
    }
}

void print_premutations_recursive(std::string str)
{
    next_premutation(str, "");
}

static void task_number_8()
{
    std::cout << "non-recursive version" << std::endl;
    print_premutations_recursive("main");
}