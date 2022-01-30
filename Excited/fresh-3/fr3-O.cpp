#include <cstdio>
#include <cstring>

int ans[10001];

int flag(const int &i, const int &n, const int &m)
{
    if((n - i) % (m + 1) == 0) return 0;
    else return 1;
}

int main()
{
    int n, m, c;
    std::scanf("%d", &c);
    while(c--)
    {
        std::scanf("%d %d", &n, &m);
        if(n <= m) 
        {
            std::printf("Grass\n");
            continue;
        }
        for(int i = n; i >= 0; i--)
        {
            ans[i] = flag(i, n, m);
        }
        if(ans[0] == 0) std::printf("Rabbit\n");
        else std::printf("Grass\n");
    }
    return 0;
}