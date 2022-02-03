#include <set>
#include <iostream>
#include <algorithm>
#include <utility>

// #define DEBUG 1

int main()
{
    #ifndef DEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif

    std::set<int> A, B;
    int acount, bcount, tmp;
    while(std::cin >> acount >> bcount)
    {
        A.clear();
        B.clear();
        while(acount--) 
        {
            std::cin >> tmp;
            A.emplace(std::move(tmp));
        }
        while(bcount--) 
        {
            std::cin >> tmp;
            B.emplace(std::move(tmp));
        }
        for(const auto &i: B) A.emplace(i);
        for(const auto &i: A) std::cout << i << ' ';
        std::cout << '\n';
    }
    return 0;
}