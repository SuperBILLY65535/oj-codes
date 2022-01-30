#include <deque>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

typedef int T;

struct item{
    T value, price, amount;
    static item new_item(T _v, T _p, T _a)
    {
        item tmp;
        tmp.value = _v; tmp.price = _p; tmp.amount = _a;
        return tmp;
    }
};

T backpack_full(
    const T &capacity, 
    const std::deque<item> &items
)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(item i: items)
    for(T v = i.price; v <= capacity; v++)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-i.price] + i.value
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}

int main()
{
    std::deque<item> food;
    int cases, max_cal, cal, hap;
    while(std::cin >> cases)
    {
        food.clear();
        while(cases--) 
        {
            std::cin >> hap >> cal;
            food.push_back(item::new_item(hap, cal, 1));
        }
        std::cin >> max_cal;
        std::cout << backpack_full(max_cal, food) << '\n';
    }
    return 0;
}