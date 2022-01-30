#include <iostream>
#include <cstring>

const int maxn = 501;

bool map[maxn][maxn];
int gf[maxn];
bool have_gf[maxn];

bool dfs(const int& girl, const int& boy)
{
    for(int b = 1; b <= boy; b++)
    if(map[girl][b] && !have_gf[b])
    {
        have_gf[b] = true;
        if(gf[b] == -1 || dfs(gf[b], boy))
        {
            gf[b] = girl;
            return true;
        }
        have_gf[b] = false;
    }
    return false;
}

int hungary(const int &girl, const int &boy)
{
    int res = 0;
    std::memset(gf, -1, sizeof(gf));
    for(int g = 1; g <= girl; g++)
    {
        std::memset(have_gf, false, sizeof(have_gf));
        if(dfs(g, boy)) res++;
    }
    return res;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rel, bcount, gcount, b, g;
    while(std::cin >> rel)
    {
        if(rel == 0) break;

        std::memset(map, 0, sizeof(map));

        std::cin >> gcount >> bcount;
        while(rel--)
        {
            std::cin >> g >> b;
            map[g][b] = true;
        }
        std::cout << hungary(gcount, bcount) << '\n';
    }
    return 0;
}