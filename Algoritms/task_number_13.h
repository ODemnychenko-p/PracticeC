//
// Created by Oleksandr Demnychenko on 20.12.2024.
//

#include "iostream"
#include "vector"
#include "array"
#include "stack"

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;
    while(i <= j)
    {
        while(i <= j && *i <= pivot)
        {
            j++;
        }

        while(i <= j && *j > pivot)
        {
            j--;
        }

        if(i < j)
        {
            std::iter_swap(i, j);
        }
    }

    std::iter_swap(i - 1, first);
    return i - 1;
}

template <class RandomIt, class Compare>
RandomIt partitionc(RandomIt first, RandomIt last, Compare comp)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;
    while(i <= j)
    {
        while( i <= j && comp(*i, pivot))
        {
            i++;
        }

        while(i <= j && !comp(*j, pivot))
        {
            j--;
        }

        if(i < j)
        {
            std::iter_swap(i, j);
        }
    }

    std::iter_swap(i - 1, first);
    return i - 1;
}

template <class RandomIt, class Compare>
void quicksort2(RandomIt first, RandomIt last, Compare comp)
{
    if(first < last)
    {
        auto p = partitionc(first, last, comp);
        quicksort2(first, p, comp);
        quicksort2(p + 1, last, comp);
    }
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last)
{
    if(first < last)
    {
        auto p = partition(first, last);
        quicksort(first, p);
        quicksort(p + 1, last);
    }
}

template <class RandomIt>
void quicksorti(RandomIt first, RandomIt last)
{
    std::stack<std::pair<RandomIt, RandomIt>> st;
    st.push(std::make_pair(first, last));
    while(!st.empty())
    {
        auto iters = st.top();
        st.pop();

        if(iters.second - iters.first < 2)
        {
            continue;
        }

        auto p = partition(iters.first, iters.second);
        st.push(std::make_pair(iters.first, p));
        st.push(std::make_pair(p+1, iters.second));
    }
}

static void task_number_13()
{
    std::vector<int> v{ 1, 5, 3, 8, 6, 3, 9, 7, 4 };
    quicksort(std::begin(v), std::end(v));

    std::array<int, 9> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quicksort(std::begin(a), std::end(a));

    int b[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    quicksort(std::begin(b), std::end(b));
}

static void task_number_13_2()
{
    std::vector<int> v{ 1, 5, 3, 8, 6, 3, 9, 7, 4 };
    quicksort2(std::begin(v), std::end(v), std::greater<>());
}

static void task_number_13_3()
{
    std::vector<int> v{ 1, 5, 3, 8, 6, 3, 9, 7, 4 };
    quicksorti(std::begin(v), std::end(v));
}