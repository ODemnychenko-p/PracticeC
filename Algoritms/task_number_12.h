#include "iostream"
#include "vector"
#include "type_traits"
#include <algorithm>
#include <utility>

class Book
{
public:
    int id;
    std::string title;
    std::string author;
};

template <typename T, typename A, typename F>
using ResultType = typename std::decay<typename std::invoke_result<typename std::decay<F>::type&(const typename std::vector<T, A>::const_reference)>::type>::type;

template <typename T, typename A, typename F, typename R = ResultType<T, A, F>>
std::vector<R> select(std::vector<T,A> const& c, F&& f)
{
    std::vector<R> v;
    std::transform(std::cbegin(c), std::cend(c), std::back_inserter(v), std::forward<F>(f));

    return v;
}

static void task_number_12()
{
    std::vector<Book> books{
            {101, "The C++ Programming Language", "BjarneStroustrup"},
            {203, "Effective Modern C++", "Scott Mayers"},
            {404, "The Modern C++ Programming Cookbook", "Marius Bancila"}
    };

    auto titles = select(books, [](Book const & b){
        return b.title;
    });

    for(auto const & title: titles)
    {
        std::cout << title << std::endl;
    }
}