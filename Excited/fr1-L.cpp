#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void solve(std::vector<int> &deg) 
{
    auto cur = deg.begin();
    while(*cur > 0)
    {
        for(int i = 0; i < *cur; i++) {
            *(cur + i) --;
        }
        *cur = 0;
        cur++;
        std::sort(cur, deg.end(), std::greater<int>());
    }
    for(auto i: deg)
    {
        if(i < 0) {
            std::cout << "no\n";
            return;
        }
    }
    std::cout << "yes\n";
    return;
}

int main() 
{
    int tests, seq;
    std::vector<int> deg;
    std::cin >> tests;
    while(tests--) 
    {
        deg.clear();
        std::cin >> seq;
        deg.resize(seq);
        while(seq--) 
        {
            std::cin >> deg[seq];
        }
        std::sort(deg.begin(), deg.end(), std::greater<int>());
        solve(deg);
    }
    return 0;
}