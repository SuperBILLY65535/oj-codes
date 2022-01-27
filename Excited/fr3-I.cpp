#include <cstdio>

int main() 
{
    int c, n, m;
    std::scanf("%d", &c);
    while(c--)
    {
        std::scanf("%d %d", &n, &m);
        if(n % (m+1) == 0) std::printf("second\n");
        else std::printf("first\n");
    }
    return 0;
}