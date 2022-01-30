#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>

void solve(int n)
{
    std::vector<int> v;
    v.resize(n);
    std::iota(v.begin(), v.end(), 1);
    do 
    {
        for(auto &&i: v) std::cout << i;
        std::cout << '\n';
    } 
    while(std::next_permutation(v.begin(), v.end()));
}

bool vis[10];

void dfs(int cur, const int &size, const int &maxsize)
{
    if(size == maxsize) 
    {
        std::cout << cur << '\n';
        return;
    }
    for(int i = 1; i <= maxsize; i++) if(!vis[i])
    {
        vis[i] = true;
        dfs(cur * 10 + i, size + 1, maxsize);
        vis[i] = false;
    }
}

int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while(std::cin >> n) 
    {
        solve(n);    
        // this is not time-efficient enough
        // std::memset(vis, 0, sizeof(vis));
        // dfs(0, 0, n);
    }
    return 0;
}