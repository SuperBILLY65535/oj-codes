#include <deque>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

typedef int T;

struct item{
    T value, weight, amount;
    static item new_item(T _v, T _w, T _a)
    {
        item tmp;
        tmp.value = _v; tmp.weight = _w; tmp.amount = _a;
        return tmp;
    }
};

T backpack_01(
    const T &capacity, 
    const std::deque<item> &items
)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(item i: items)
    for(T v = capacity; v >= i.weight; v--)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-i.weight] + i.value
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}

