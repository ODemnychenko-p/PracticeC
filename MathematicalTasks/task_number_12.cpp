#include <utility>
#include <vector>
#include <iostream>

//
// Created by O.Demnychenko on 04.08.2024.
//
std::pair<unsigned long long, long> longest_collatz
        (unsigned long long const limit)
{
    long length = 0;
    unsigned long long number = 0;
    std::vector<int> cache(limit + 1, 0);

    for(unsigned long long i = 2; i <= limit; i++) {
        auto n = i;
        long steps = 0;
        while (n != 1 && n >= i) {
            if ((n % 2) == 0) {
                n = n / 2;
            } else {
                n = n * 3 + 1;
            }
            steps++;
        }
        cache[i] = steps + cache[n];

        if (cache[i] > length) {
            length = cache[i];
            number = i;
        }
    }
    return std::make_pair(number, length);
}

int main()
{
   auto t = longest_collatz(1000).first;
   auto t2 = longest_collatz(1000).second;
}