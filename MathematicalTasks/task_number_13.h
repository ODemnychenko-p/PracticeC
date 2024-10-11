//
// Created by O.Demnychenko on 8/11/2024.
//
#include <random>
#include <array>
#include <iostream>

template <typename E = std::mt19937, typename D = std::uniform_real_distribution<>>
        double compute_pi(E& Engine, D& dist, int const samples = 1000000)
{
       auto hit = 0;
       for(auto i = 0; i < samples; i++)
       {
           auto x = dist(Engine);
           auto y = dist(Engine);
           if(y <= std::sqrt(1 - std::pow(x, 2)))
           {
               hit += 1;
           }
       }
       return 4.0 * hit / samples;
}
static void task_number_13()
{
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937 {seq};
    auto dist = std::uniform_real_distribution<>(0, 1);
    for(auto j = 0; j < 10; j++)
    {
        std::cout << compute_pi(eng, dist) << std::endl;
    }
}