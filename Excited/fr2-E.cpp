#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

std::vector<unsigned long long> mul = {2u, 3u, 5u, 7u};
const unsigned long long m = 2000000001u;

int main() {
    std::vector<unsigned long long> ls = {1};
    ls.reserve(5900);
    std::vector<unsigned long long>::iterator cur = ls.begin();
    unsigned long long tmp;
    while(ls.size() < 5842)
    {
        for(auto i: mul) 
        {
            tmp = *cur * i;
            if(tmp <= m) ls.push_back(tmp);
        }
        cur++;
    }
    std::sort(ls.begin(), ls.end());
    unsigned n;
    while(std::cin >> n)
    {
        if(n == 0) break;
        std::cout << ls[n] << '\n';
    }
    return 0;
}