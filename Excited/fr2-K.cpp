#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int no_way = 0x7fffffff;

int main()
{
    
    int cities, road, from, to, len, map[200][200], ans, vis[200], dis[200];
    while(std::cin >> cities >> road)
    {
        for(int i = 0; i < cities; i++)
        {
            dis[i] = no_way;
            for(int j = 0; j < cities; j++)
            {
                map[i][j] = no_way;
            }
        }
        std::memset(vis, 0, sizeof(vis));

        while(road--)
        {
            std::cin >> from >> to >> len;
            map[from][to] = std::min(map[from][to], len);
            map[to][from] = map[from][to];
        }
        
        std::cin >> from >> to;
        
        int cur = from, next, min_len = no_way;
        dis[from] = 0;
        vis[from] = 1;

        while(cur != to)
        {
            // to do:
            // detect the shortest path 
            // update path length
            min_len = no_way;
            for(int i = 0; i < cities; i++)
            {
                if(map[cur][i] != no_way)
                {
                    dis[i] = std::min(dis[i], dis[cur] + map[cur][i]);
                }
                if(!vis[i] && dis[i] < min_len)
                {
                    min_len = dis[i];
                    next = i;
                }
            }
            if(min_len == no_way) break;
            cur = next;
            vis[cur] = 1;
        }
        if(dis[to] == no_way) std::printf("-1\n");
        else printf("%d\n", dis[to]);
    }
    return 0;
}