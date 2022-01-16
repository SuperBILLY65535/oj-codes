#include <iostream>
#include <algorithm>
#include <deque>

void fib(unsigned k, unsigned *v);

int main() {
    unsigned k, m = 0, v[1000001] = {1, 2};
    std::deque<unsigned> q;
    q.clear();
    while(std::cin >> k) {
        q.push_back(k);
        m = std::max<unsigned>(m, k);
    }
    fib(m, v);
    for(auto i: q) {
        if(v[i] == 0) {
            std::cout << "yes" << std::endl;
        }
        else {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}

void fib(unsigned k, unsigned *v) {
    if(k < 2) return;
    for(unsigned i = 2; i <= k; i++) {
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= 3;
    }
    return;
}