#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
// #define DEBUG

int main() 
{
    #ifndef DEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif

    int n, m;
    std::vector<int> seq;
    while(std::cin >> n >> m)
    {
        seq.resize(n);
        std::iota(seq.begin(), seq.end(), 1);
        while(--m)
        {
            std::next_permutation(seq.begin(), seq.end());
        }
        for(const auto &i: seq) std::cout << i << ' ';
        std::cout << '\n';
    }
    return 0;
}