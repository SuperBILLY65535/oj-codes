#include <iostream>
#include <algorithm>

inline int dif(const int& lhs, const int& rhs)
{
    return std::abs(lhs * lhs - rhs * rhs);
}

int main() {
    int n, k, weight[2001], dp[2001][2001];
    while(std::cin >> n >> k)
    {
        for(int i = 1; i <= n; i++) std::cin >> weight[i];
        std::sort(weight, weight+n);
        for(int i = 1; i <= k; i++)
        {
            for(int j = 2; j <= 2*i; j+=2)
            {
                dp[i][2*i] += dif(weight[j-1], weight[j]);
            }
            for(int j = 2*i+1; j <= n; j++)
            {
                dp[i][j] = std::min(
                    dp[i][j-1],
                    (dp[i][j-2] + dif(weight[j], weight[j-1]))
                );
            }
        }
        std::cout << dp[k][n] << '\n';
    }
    return 0;
}