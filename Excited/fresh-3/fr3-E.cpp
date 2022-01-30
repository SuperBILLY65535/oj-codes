#include <iostream>
#include <cstring>

const int maxn = 101;

bool map[maxn][maxn], used[maxn];
int linker[maxn];

bool dfs(const int &a, const int &bm)
{
    for(int b = 0; b < bm; b++)
    if(map[a][b] && !used[b])
    {
        used[b] = true;
        if(linker[b] == -1 || dfs(linker[b], bm))
        {
            linker[b] = a;
            return true;
        }
        // used[b] = false;
    }
    return false;
}

int hungary(const int &am, const int &bm)
{
    int res = 0;
    std::memset(linker, -1, sizeof(linker));
    for(int a = 0; a < am; a++)
    {
        std::memset(used, false, sizeof(false));
        if(dfs(a, bm)) res++;
    }
    return res;
}

int main() 
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int amodes, bmodes, conf, id, a, b;
    while(std::cin >> amodes)
    {
        if(amodes == 0) break;
        std::cin >> bmodes >> conf;
        std::memset(map, 0, sizeof(map));
        while(conf--)
        {
            std::cin >> id >> a >> b;
            if(a != 0 && b != 0) map[a][b] = 1;
        }
        std::cout << hungary(amodes, bmodes) << '\n';
    }
    return 0;
}