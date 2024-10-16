//
// Created by O.Demnychenko on 10/16/2024.
//
#include <chrono>
#include <iostream>
#include <date/iso_week.h>
#include "date/date.h"
int day_of_year(int const y, unsigned int const m, unsigned int const d)
{
    using namespace std::chrono;
    if(m < 1 || m > 12 || d < 1 || d > 31)
    {
        return 0;
    }

    return (sys_days{year{y} / month{m} / day{d}} -
            sys_days{year{y} / std::chrono::month(1) / 0}).count();
}

unsigned int calendar_week(int const y, unsigned int const m, unsigned int const d)
{
    using namespace std::chrono;
    if(m < 1 || m > 12 || d < 1 || d > 31)
    {
        return 0;
    }

    auto const dt = std::chrono::year_month_day{year{y}, month{m}, day{d}};
    auto const tiso = iso_week::year_weeknum_weekday{dt};

    return (unsigned int)tiso.weeknum();
}

static void task_number_4()
{
    int y = 0;
    unsigned int m = 0, d = 0;
    std::cout << "Year:"; std::cin >> y;
    std::cout << "Month:"; std::cin >> m;
    std::cout << "Day:"; std::cin >> d;

    std::cout << "Calendar week:" << calendar_week(y, m, d) << std::endl;
    std::cout << "Day of year:" << day_of_year(y, m, d) << std::endl;
}