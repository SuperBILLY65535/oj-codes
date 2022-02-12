#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string c;
    std::deque<char> s;
    int t = 0;

    while(std::cin >> c) {
        if(c[0] == '-') break;

        s.clear();

        for(const auto &i: c) {
            if(!s.empty()){
                if(i == '}' && s.back() == '{') s.pop_back();
                else s.push_back(i);
            }
            else s.push_back(i);
        }

        int lcount = std::count(s.begin(), s.end(), '{');
        int rcount = s.size() - lcount;

        std::cout 
            << ++t 
            << ". "
            << lcount/2 + rcount/2 + lcount%2 + rcount%2 
            << '\n';
    }
    return 0;
}