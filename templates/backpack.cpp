#include <vector>
#include <algorithm>
#include <cstring>

template<class T = int>
T backpack_01(T capacity, T *weight, T *value, size_t items)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(int i = 0; i < items; i++)
    for(int v = capacity; v >= weight[i]; v--)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-weight[i]] + value[i];
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}

template<class T = int>
T backpack_full(T capacity, T *weight, T *value, size_t items)
{
    T *dp = new T[capacity + 1];
    std::memset(dp, 0, (capacity + 1) * sizeof(T));
    for(int i = 0; i < items; i++)
    for(int v = weight[i]; v <= capacity; v++)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-weight[i]] + value[i];
        );
    T ans = dp[capacity];
    delete[] dp;
    return ans;
}