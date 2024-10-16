//
// Created by O.Demnychenko on 10/16/2024.
//
#include <chrono>
#include <iostream>

using namespace std::chrono;

struct user
{
    std::string Name;
    std::chrono::time_zone const* Zone;

    explicit user(std::string_view name, std::string_view zone): Name{name.data()}, Zone(std::chrono::locate_zone(zone.data())){}
};

template <class Duration, class TimeZonePtr>
void print_meeting_times(
        std::chrono::zoned_time<Duration, TimeZonePtr> const& time,
        std::vector<user> const& users
        )
{
    std::cout
    << std::left
    << std::setw(15)
    << std::setfill(' ')
    << "Local time: "
    << time
    << std::endl;

    for(auto const& user: users)
    {
        std::cout
        << std::left
        << std::setw(15)
        << std::setfill(' ')
        << user.Name
        << std::chrono::zoned_time<Duration, TimeZonePtr>(user.Zone, time)
        << std::endl;
    }
}

static void task_number_5()
{
    std::vector<user> users
            {
                user{"Ildiko", "Europe/Budapest"},
                user{"Jens", "Europe/Berlin"},
                user{"Jane", "America/New_York"}
            };

    unsigned int h,m;
    std::cout << "Hour:"; std::cin >> h;
    std::cout << "Minutes:"; std::cin >> m;

    std::chrono::year_month_day today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());

    auto localtime = std::chrono::zoned_time<std::chrono::minutes>(std::chrono::current_zone(),
                                                                   static_cast<std::chrono::local_days>(today) +
                                                                   std::chrono::hours{h} +
                                                                   std::chrono::minutes{m});
    print_meeting_times(localtime, users);
}