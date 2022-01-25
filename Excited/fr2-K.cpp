#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int no_way = 0x7fffffff;

int main()
{
    
    int cities, road, from, to, len, roads[200][200], ans, vis[200], dis[200];
    while(std::cin >> cities >> road)
    {
        for(int i = 0; i < cities; i++)
        for(int j = 0; j < cities; j++)
        roads[i][j] = no_way;
        std::memset(vis, 0, sizeof(vis));
        for(int i = 0; i < cities; i++) dis[i] = no_way;

        while(road--)
        {
            std::cin >> from >> to >> len;
            roads[from][to] = std::min(roads[from][to], len);
            roads[to][from] = roads[from][to];
        }
        std::cin >> from >> to;
        
        int min = no_way, start = from, next, min_len = no_way;
        dis[from] = 0;

        
        
    }
}