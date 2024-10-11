//
// Created by Oleksandr Demnychenko on 31.08.2024.
//
template <class Compare, typename T>
T minimumc(Compare comp, T const a, T const b)
{
    return comp(a, b) ? a : b;
}

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args)
{
    return minimumc(comp, a, minimumc(comp, args...));
}

static void task_number_4()
{
    auto x = minimumc(std::less<>(), 5, 1, 2, 3, 0);
    std::cout << x;
}