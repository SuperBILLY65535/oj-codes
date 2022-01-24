#include <iostream>
#include <vector>

const int no_way = 0x7fffffff;

int main()
{
    
    int cities, road, from, to, len, roads[200][200], ans;
    while(std::cin >> cities >> road)
    {
        for(int i = 0; i < cities; i++)
        for(int j = 0; j < cities; j++)
        roads[i][j] = no_way;

        while(road--)
        {
            std::cin >> from >> to >> len;
            roads[from][to] = roads[to][from] = len;
        }
        std::cin >> from >> to;
        
        
    }
}