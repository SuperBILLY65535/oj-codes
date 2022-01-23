#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstring>

typedef int T;

struct item
{
    T value, weight, amount;
    static item new_item(T _v, T _w, T _a)
    {
        item tmp;
        tmp.value = _v; tmp.weight = _w; tmp.amount = _a;
        return tmp;
    }
};

T backpack_full(
    const T &capacity, 
    const std::deque<item> &items
)
{
    T *dp = new T[capacity + 1];
    for(int i = 1; i <= capacity; i++) dp[i] = 0x7f000000;
    dp[0] = 0;
    for(item i: items)
    for(T v = i.weight; v <= capacity; v++)
    {
        dp[v] = std::min<T>(
            dp[v],
            dp[v-i.weight] + i.value
        );
    }
    T ans = dp[capacity];
    delete[] dp;
    return ans;
};

int main() 
{
    int tests, E, F, N, V, W, ans;
    std::deque<item> coins;
    std::cin >> tests;
    while(tests--)
    {
        std::cin >> E >> F >> N;
        coins.clear();
        while(N--)
        {
            std::cin >> V >> W;
            coins.push_back(item::new_item(V, W, 1));
        }
        ans = backpack_full(F-E, coins);
        if(ans == 0x7f000000) std::printf("This is impossible.\n");
        else std::printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
    }
    return 0;
}