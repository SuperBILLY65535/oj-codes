#include <iostream>
#include <algorithm>
#include <functional>

bool cnt(int *deg, int size) {
    for(int i = 0; i < size; i++) {
        if(deg[i] != 0) return false;
    }
    return true;
}

bool flag2(int *deg, int size) {
    for(int i = 0; i < size; i++) {
        if(deg[i] < 0) return true;
    }
    return false;
}

void solve(int *deg, int size) {
    for(int i = 0; i < size; ++i) {
        std::sort(deg + i, deg + size, std::greater<int>());
        if(cnt(deg + i, size - i)) {
            std::cout << "yes\n";
            return;
        }
        if(flag2(deg + i, size - i)) {
            std::cout << "no\n";
            return;
        }
        for(int j = 1; j <= deg[i]; j++) {
            deg[i + j]--;
        }
    }
}

int main() {
    int tests, seq, deg[1000];
    std::cin >> tests;
    while(tests--) {
        std::cin >> seq;
        int i = seq;
        while(i--) {
            std::cin >> deg[i];
            solve(deg, seq);
        }
    }
    return 0;
}