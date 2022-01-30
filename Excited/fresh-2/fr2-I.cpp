#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main()
{
    int cases, cash, dp[3][201], leftover;
    const int items[3] = {3, 4, 7};
    std::memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i <= 200; i++) dp[0][i] = i % 3;
    for(int i = 1; i <= 2; i++)
    for(int v = 0; v <= 200; v++)
    {
        if(v < items[i]) dp[i][v] = dp[i-1][v];
        else dp[i][v] = std::min({
            dp[i-1][v], dp[i-1][v-items[i]], dp[i][v-items[i]]
        });
    }

    for(std::cin >> cases; cases>0; cases--)
    {
        std::cin >> cash; 
        leftover = cash % 50; cash /= 50;
        std::cout << dp[2][cash]*50 + leftover << '\n';
    }
    return 0;
}