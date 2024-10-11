//
// Created by Oleksandr Demnychenko on 22.09.2024.
//
#include <string>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>,
        std::allocator<Elem>>;

template<class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>,
        std::allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const& text)
{
    tstringstream<Elem> result;
    bool newWorld = true;
    for(auto const ch: text)
    {
        newWorld = newWorld || std::ispunct(ch) || std::isspace(ch);
        if(std::isalpha(ch))
        {
            if(newWorld)
            {
                result << static_cast<Elem>(std::toupper(ch));
                newWorld = false;
            }
            else
            {
                result << static_cast<Elem>(std::tolower(ch));
            }
        }
        else
        {
            result << ch;
        }
    }
    return result.str();
}

static void task_number_3()
{
    using namespace std::string_literals;
    assert("The C++ Challenger"s == capitalize("the c++ challenger"s));
    assert("This Is An Example, Should Work!"s == capitalize("THIS IS an ExamplE, should wORk!"s));
}