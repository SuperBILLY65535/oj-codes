#include <cstdio>

int main() {
    int ways[60]; ways[0] = 0; ways[1] = 1;
    for(int i = 2; i < 60; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }
    int n, a, b;
    std::scanf("%d", &n);
    while(n--) {
        std::scanf("%d %d", &a, &b);
        std::printf("%d\n", ways[b - a + 1]);
    }
    return 0;
}