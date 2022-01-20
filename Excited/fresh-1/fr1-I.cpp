#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
    unsigned tests, moves, from, to, corridor[200];
    std::cin >> tests;
    while(tests--) {
        std::memset(corridor, 0, sizeof(corridor));
        std::cin >> moves;
        while(moves--) {
            std::cin >> from >> to;
            if(to < from) std::swap(from, to);
            for(unsigned i = (from - 1) / 2; i <= (to - 1) / 2; i++) {
                corridor[i]++;
            }
        }
        std::cout 
            << (*std::max_element(corridor, corridor + 200)) * 10 
            << std::endl;
    }
    return 0;
}