//
// Created by O.Demnychenko on 10/15/2024.
//

#include <chrono>

unsigned int week_day (int const y, unsigned int const m, unsigned int const d)
{
    using namespace std::chrono;

    if(m < 1 || m > 12 || d < 1 || d> 31)
    {
        return 0;
    }

    auto const dt = std::chrono::year_month_day{year{y}, month{m}, day{d}};
    auto const tiso = std::chrono::year_month_weekday{dt};
    return tiso.weekday().iso_encoding();
}

static void task_number_3()
{
    auto wday = week_day(2018, 5, 9);
}