#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

//
// Created by Oleksandr Demnychenko on 11.09.2024.
//
template<class C, class T>
bool contains(C const& c, T const& value)
{
    return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class... T>
bool contains_any(C const& c, T &&... value)
{
    return (... || contains(c, value));
}

template<class C, class... T>
bool contains_all(C const& c, T &&... value)
{
    return (... && contains(c, value));
}

template<class C, class... T>
bool contains_none(C const& c, T &&... value)
{
    return !contains_any(c, std::forward<T>(value)...);
}

static void task_number_6()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    //std::cout << contains(numbers, 3);
    std::cout << contains_any(numbers, 0.7f, 0.1, 0.5f, 5);
    //std::cout << contains_all(numbers, 3);
    //std::cout << contains_none(numbers, 3);
}