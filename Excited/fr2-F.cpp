#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

const int maxv = 1000 + 1;

// template<class T = int>
// T backpack_01(T capacity, T *weight, T *value, size_t items)
// {
//     static T dp[maxv];
//     std::memset(dp, 0, sizeof(dp));
//     for(size_t i = 0; i < items; i++)
//     for(T v = capacity; v >= value[i]; v--)
//         dp[v] = std::max<T>(
//             dp[v],
//             dp[v-weight[i]] + value[i]
//         );
//     return dp[capacity];
// }

const int maxn = 1000;

int main() {
    int tests, num, volume, weight[maxn], value[maxn], dp[maxv];
    std::cin >> tests;
    while(tests--)
    {
        std::memset(dp, 0, sizeof(dp));
        std::cin >> num >> volume;
        for(int i = 0; i < num; i++) std::cin >> value[i];
        for(int i = 0; i < num; i++) std::cin >> weight[i];
        // std::cout << backpack_01(volume, weight, value, num) << '\n'; 

        for(int i = 0; i < num; i++)
        for(int v = volume; v >= weight[i]; v--)
            dp[v] = [] (const int &a, const int &b) ->int{
                return a>b?a:b;
            }(dp[v], dp[v-weight[i]]+value[i]);
        
        std::cout << dp[volume] << '\n';
    }
    return 0;
}