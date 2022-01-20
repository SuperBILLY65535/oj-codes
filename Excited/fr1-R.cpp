#include <iostream>

int main() {
    int ways[41], n, q;
    ways[0] = 0; ways[1] = 1;
    for(int i = 2; i <= 40; i++)
    {
        ways[i] = ways[i - 1] + ways[i - 2];
    }
    std::cin >> n;
    while(n--) {
        std::cin >> q;
        std::cout << ways[q] << '\n';
    }
    return 0;
}