//
// Created by O.Demnychenko on 10/15/2024.
//
#include <chrono>
#include <thread>
#include <functional>

template <typename Time = std::chrono::milliseconds, typename Clock = std::chrono::high_resolution_clock>
struct perf_primer
{
    template<typename F, typename... Args>
    static Time duration(F&& f, Args... args)
    {
        auto start = Clock::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        auto end = Clock::now();
        return std::chrono::duration_cast<Time>(end - start);
    }
};

void f()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void g()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

static void task_number_1()
{
    auto t1 = perf_primer<std::chrono::microseconds>::duration(f);
    auto t2 = perf_primer<std::chrono::milliseconds>::duration(g, 1, 2);
    auto total = std::chrono::duration<double, std::nano>(t1 + t2).count();
}