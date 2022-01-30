#define ctype int
#include <cstdio>
#include <cstring>
#include <set>

const int maxn = 1001;
const ctype no_way = 0x3f3f3f3f;    // no way through

bool vis[maxn], pre[maxn];

void djikstra(ctype map[][maxn], ctype dis[], const int &begin, const int &nodes)
{
    for(int i = 0; i < nodes; i++)
    {   // initialization
        vis[i] = false;
        dis[i] = no_way;
        pre[i] = -1;
    }
    
    int cur;
    ctype Min = no_way;
    dis[begin] = 0;
    for(int j = 0; j < nodes; j++)
    {
        cur = -1;
        Min = no_way;
        for(int i = 0; i < nodes; i++) // find the currently shortest path
            if(!vis[i] && dis[i] <= Min)
            {
                Min = dis[i];
                cur = i;
            }
        if(cur == -1) break;
        
        vis[cur] = true;    // visit node_cur

        for(int i = 0; i < nodes; i++)
            if(!vis[i] && map[cur][i] != no_way && dis[i] > dis[cur] + map[cur][i])
            {
                dis[i] = dis[cur] + map[cur][i];
                pre[i] = cur;
            }
    }
    return;
}

int main()
{
    ctype map[maxn][maxn], dis[maxn], t, s, d, b, e, l;
    std::set<int> dest;
    while(std::scanf("%d %d %d", &t, &s, &d) == 3)
    {
        dest.clear();
        for(int i = 1; i <= t; i++)
        for(int j = 1; j <= t; j++)
            map[i][j] = no_way;
        while(t--)
        {
            std::scanf("%d %d %d", &b, &e, &l);
            map[b][e] = std::min(map[b][e], l);
            map[e][b] = map[b][e];
        }
        while(s--)
        {
            std::scanf("%d", &b);
            map[0][b] = 0;
        }
        while(d--)
        {
            std::scanf("%d", &e);
            dest.emplace(e);
        }
        djikstra(map, dis, 0, maxn);
        int Min = no_way;
        for(const auto &i: dest)
        {
            if(dis[i] < Min) Min = dis[i];
        }
        std::printf("%d\n", Min);
    }
    return 0;
}