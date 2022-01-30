#include <cstdio>
#include <cstring>

int ans[1101];

int flag(const int &i, const int &m, const int &n)
{
    if((m - i) % (n + 1) == 0) return 0;
    else return 1;
}

int main()
{
    int m, n;
    while(std::scanf("%d %d", &m, &n) == 2)
    {
        if(m <= n) 
        {
            for(int i = m; i <= n; i++) std::printf("%d ", i);
            std::printf("\n");
            continue;
        }
        else
        {
            for(int i = m; i >= 0; i--)
            {
                ans[i] = flag(i, m, n);
            }
        }
        if(ans[0] == 0) 
        {
            std::printf("none\n");
            continue;
        }
        else for(int i = 1; i <= n; i++) 
        if(ans[i] == 0)
            std::printf("%d ", i);
        
        std::printf("\n");
    }
    return 0;
}