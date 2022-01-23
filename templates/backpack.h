#include <deque>
#include <algorithm>
#include <cstring>

typedef int T;

T backpack_01(
    const T &capacity, 
    T *weight, 
    T *value, 
    const size_t &items
)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(size_t i = 0; i < items; i++)
    for(T v = capacity; v >= weight[i]; v--)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-weight[i]] + value[i]
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}

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

T backpack_full(
    const T &capacity, 
    T *weight, 
    T *value, 
    const size_t &items
)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(size_t i = 0; i < items; i++)
    for(T v = weight[i]; v <= capacity; v++)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-weight[i]] + value[i]
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}


T backpack_full(
    const T &capacity, 
    const std::deque<item> &items
)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(item i: items)
    for(T v = i.weight; v <= capacity; v++)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-i.weight] + i.value
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}


T backpack_multi(
    const T& capacity, 
    const std::deque<item> &items
)
{
    std::deque<item> it;
    it.clear();
    for(item i: items) 
    {
        item tmp = i; tmp.amount = 1;
        while(i.amount > 0)
        {
            if(i.amount % 2 == 1)
            {
                it.push_back(tmp);
            }
            i.amount /= 2;
            tmp.value *= 2;
            tmp.weight *= 2;
        }
    }
    return backpack_01(capacity, it);
}