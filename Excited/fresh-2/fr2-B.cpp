#include <iostream>
#include <algorithm>
#include <cstring>

int main() 
{
    int n, missiles[3001], len[3001], ans;
    while(std::cin >> n)
    {
        for(int i = 0; i < n; i++) std::cin >> missiles[i];
        ans = 0;
        for(int i = 0; i < n; i++) 
        {
            len[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(missiles[i] > missiles[j])
                    len[i] = std::max(len[i], len[j]+1);
            }
        }
        for(int i = 0; i < n; i++) ans = std::max(ans, len[i]);
        std::cout << ans << '\n';
    }
    return 0;
}