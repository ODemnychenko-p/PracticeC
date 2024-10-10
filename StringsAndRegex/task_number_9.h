//
// Created by O.Demnychenko on 10/7/2024.
//

#include <string>
#include <regex>
#include <cassert>

std::string transform_date(std::string_view text)
{
    auto rx = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };

    return std::regex_replace(text.data(), rx, R"($5-$3-$1)");
}

static void task_number_9()
{
    using namespace std::string_literals;
    assert(transform_date("today is 01.12.2017!"s) == "today is 2017-12-01!"s);
}