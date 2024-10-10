//
// Created by O.Demnychenko on 8/11/2024.
//

#include <string_view>
#include <algorithm>
#include <cctype>
#include <numeric>

bool validate_isbn_10(std::string_view isbn)
{
    auto valid = false;
    if(isbn.size() == 10 &&
    std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
    {
        auto w = 10;
        auto sum = std::accumulate(std::begin(isbn), std::end(isbn), 0,
                                   [&w](int const total, char const c)
                                   {
                                         return total + w-- * (c - '0');
                                   });
        valid = !(sum%11);
    }
    return valid;
}
int main()
{
    return 0;
}