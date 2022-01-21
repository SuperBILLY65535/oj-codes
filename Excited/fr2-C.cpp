#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

inline int dif(const int& lhs, const int& rhs)
{
    return (lhs-rhs)*(lhs-rhs);
}

int main() {
    int n, k, weight[2001], dp[2][2001];
    while(std::scanf("%d %d", &n, &k))
    {
        std::memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) std::scanf("%d", weight+i);

        std::sort(weight, weight+n);
        for(int i = 1; i <= k; i++)
        {
            dp[i%2][2*i] = dp[(i+1)%2][2*i-2] + dif(weight[2*i], weight[2*i-1]);
            for(int j = 2*i+1; j <= n; j++)
            {
                dp[i%2][j] = [] (const int& a, const int& b) ->int
                {
                    return a<b?a:b;
                }
                (dp[i%2][j-1], dp[(i+1)%2][j-2] + dif(weight[j], weight[j-1]));
            }
        }

        std::printf("%d\n", dp[k%2][n]);
    }
    return 0;
}