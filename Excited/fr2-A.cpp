#include <iostream>
#include <algorithm>

int main() {
    int c, n, dp[100][100];
    for(std::cin >> c; c > 0; c--)
    {
        std::cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
            {
                std::cin >> dp[i][j];
            }
        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[i][j] += std::max(dp[i+1][j], dp[i+1][j+1]);
        std::cout << dp[0][0] << '\n';
    }
    return 0;
}