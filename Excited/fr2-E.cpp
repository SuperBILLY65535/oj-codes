#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <set>

std::vector<unsigned> mul = {2u, 3u, 5u, 7u};

int main() {
    std::set<unsigned> ugly = {1};
    std::vector<unsigned> ans;
    ans.reserve(5900);
    for(const auto &i: ugly)
    {
        if(ugly.size() >= 5842) break;
        for(auto j: mul)
        {
            if(1ull * i * j <= 20'0000'0000)
            {
                ugly.emplace(i * j);
            }
        }
    }
    for(const auto &i: ugly)
    {
        ans.emplace_back(i);
    }
    int req;
    while(std::scanf("%d", &req))
    {
        if(req == 0) break;
        std::printf("%d\n", ans[req-1]);
    }
    return 0;
}