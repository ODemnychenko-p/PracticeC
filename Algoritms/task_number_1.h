#include "iostream"

template <class T, class Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue
{
    typedef typename std::vector<T>::value_type value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::reference reference;
    typedef typename std::vector<T>::const_reference const_reference;
public:
    bool empty() const noexcept { return data.empty(); }
    size_type size() const noexcept { return data.size(); }

    void push(value_type const& value) {
        data.push_back(value);
        std::push_heap(data.begin(), data.end(), comparer);
    }
    void pop() {
        std::pop_heap(data.begin(), data.end(), comparer);
        data.pop_back();
    }

    const_reference top() const {return data.front(); }

    void swap(priority_queue& other) noexcept
    {
        swap(data, other.data);
        swap(comparer, other.comparer);
    }

private:
    std::vector<T> data;
    Compare comparer;
};

template<class T, class Compare>
void swap(priority_queue<T, Compare>& lhs, priority_queue<T, Compare>& rhs)
noexcept(noexcept(lhs.swap(rhs))){
    lhs.swap(rhs);
}

static void task_number_1()
{
    priority_queue<int> q;
    for(int i: {1, 5, 3, 1, 13, 21, 8})
    {
        q.push(i);
    }
    assert(!q.empty());
    assert(q.size() == 7);

    while(!q.empty())
    {
        std::cout << q.top() << ' ';
        q.pop();
    }
}