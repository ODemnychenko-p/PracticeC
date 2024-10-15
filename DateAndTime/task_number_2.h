//
// Created by O.Demnychenko on 10/15/2024.
//

#include <chrono>
using namespace std::chrono;
inline int number_of_days(int const y1, unsigned int const m1, unsigned int const d1,
                          int const y2, unsigned int const m2, unsigned int const d2)
{
    return (sys_days{year{y1} / month{m1} / day{d1}} - sys_days{year{y2} / month{m2} / day{d2}}).count();
}

inline int number_of_days(sys_days const& first, sys_days const& last)
{
    return (last - first).count();
}

static void task_number_2()
{
    auto diff1 = number_of_days(2016, 9, 23, 2017, 5, 15);

    using namespace std::chrono_literals;
    auto diff2 = number_of_days(std::chrono::year(2016)/sep/23, std::chrono::day(15)/may/2017);
}