#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

const int maxn = 201, no_way = 0x7fffffff;
typedef int ans_type;

struct edge
{
    int from, to, len;
    edge() = default;
    bool operator() (const edge &lhs, const edge &rhs) const
    {
        return lhs.len > rhs.len;
    }
};

std::vector<std::vector<edge>> map;
std::vector<int> de;
ans_type dis[maxn], fa[maxn];
bool vis[maxn];

void Djikstra(const int &cities, const int &begin)
{
    for(auto &i: dis) i = no_way;
    std::memset(fa, -1, sizeof(fa));
    std::memset(vis, false, sizeof(vis));
    dis[begin] = 0;
    vis[begin] = true;

    std::priority_queue<edge, std::vector<edge>, edge> que;
    edge cur;
    for(const auto &i: map[begin]) 
        que.push(i);
    
    vis[begin] = true;

    int next;
    while(!que.empty())
    {
        next = -1;
        cur = que.top();
        que.pop();

        if(dis[cur.to] > dis[cur.from] + cur.len)
        {
            dis[cur.to] = dis[cur.from] + cur.len;
            fa[cur.to] = cur.from;
            if(!vis[cur.to])
            {
                vis[cur.to] = true;
                for(const auto &i: map[cur.to]) que.push(i);
            }
        }
    }
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    map.resize(maxn);

    int road, nei, dest, from;
    edge tmp;

    while(std::cin >> road >> nei >> dest)
    {
        for(auto &i: map)
        {
            i.clear();
            i.reserve(maxn);
        }
        while(road--)
        {
            std::cin >> tmp.from >> tmp.to >> tmp.len; from = tmp.from;
            map[from].emplace_back(tmp);
            // comment the two following lines if given single-directional paths
            std::swap(tmp.from, tmp.to); from = tmp.from;
            map[from].emplace_back(tmp);
        }
        while(nei--)
        {
            tmp.from = 0;
            std::cin >> tmp.to;
            map[0].emplace_back(std::move(tmp));
        }
        de.clear();
        while(dest--)
        {
            std::cin >> from;
            de.emplace_back(std::move(from));
        }
    }
}