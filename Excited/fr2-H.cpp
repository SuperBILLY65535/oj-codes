#include <deque>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

typedef int T;

struct item{
    T value, price, amount;
    static item new_item(T _v, T _w, T _a)
    {
        item tmp;
        tmp.value = _v; tmp.price = _w; tmp.amount = _a;
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
    for(T v = capacity; v >= i.price; v--)
        dp[v] = std::max<T>(
            dp[v],
            dp[v-i.price] + i.value
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
    for(auto i: items) 
    {
        item tmp = i; 
        for(int count = 1; tmp.amount >= count; count *= 2)
        {
            it.push_back(tmp);
            tmp.value *= 2;
            tmp.price *= 2;
            tmp.amount -= count;
        }
        if(tmp.amount > 0) it.push_back(item::new_item
        (
            i.value * tmp.amount,
            i.price * tmp.amount,
            1
        ));
    }
    return backpack_01(capacity, it);
}

int main()
{
    int cases, money, rice_count, weight, price, count;
    std::deque<item> rice;
    for(std::cin >> cases; cases>0; cases--)
    {
        std::cin >> money >> rice_count;
        rice.clear();
        while(rice_count--)
        {
            std::cin >> price >> weight >> count;
            rice.push_back(item::new_item(
                weight,
                price, 
                count
            ));
        }
        std::cout << backpack_multi(money, rice) << '\n';
    }
    return 0;
}