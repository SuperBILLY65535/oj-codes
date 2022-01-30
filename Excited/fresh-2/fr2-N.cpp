#include <cstdio>
#include <cstring>
#include <deque>
#include <utility>

struct stat{
    int fl, cnt;
    stat(const int &floor, const int &count)
    {
        fl = floor;
        cnt = count;
    }
    stat() = default;
};

std::deque<stat> s;
bool vis[201];

void new_stat(const int &floor, const int &count)
{
    if(vis[floor])return;
    stat tmp(floor, count); 
    s.push_back(std::move(tmp));
}

int bfs(int begin, int end, int k[], int ceiling)
{
    s.clear();
    std::memset(vis, 0, sizeof(vis));
    new_stat(begin, 0);
    vis[begin] = true;
    stat tmp;
    while(!s.empty())
    {
        tmp = s.front();
        if(tmp.fl == end) return tmp.cnt;
        if(k[tmp.fl] == 0){
            s.pop_front();
            continue;
        }
        if(tmp.fl - k[tmp.fl] >= 1)
        {
            new_stat(tmp.fl - k[tmp.fl], tmp.cnt + 1);
            vis[tmp.fl - k[tmp.fl]] = true;
        }
        if(tmp.fl + k[tmp.fl] <= ceiling)
        {
            new_stat(tmp.fl + k[tmp.fl], tmp.cnt + 1);
            vis[tmp.fl + k[tmp.fl]] = true;
        }
        s.pop_front();
    }
    return -1;
}

int main()
{
    int n, a, b, k[201];
    while(std::scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        std::scanf("%d %d", &a, &b);
        for(int i = 1; i <= n; i++) std::scanf("%d", k+i);
        std::printf("%d\n", bfs(a, b, k, n));
    }
    return 0;
}