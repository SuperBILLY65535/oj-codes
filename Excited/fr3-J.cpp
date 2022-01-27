#include <cstdio>
#include <utility>

size_t count(size_t k)
{
    size_t ans = 0;
    while(k>0)
    {
        if(k%2) ans++;
        k /= 2;
    }
    return ans;
}

int main() {
    size_t t;
    while(std::scanf("%u", &t) == 1)
    {
        if(count(t) % 2) std::printf("Kiki\n");
        else std::printf("Cici\n");
    }
    return 0;
}