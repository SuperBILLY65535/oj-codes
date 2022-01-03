#include <cstdio>
using namespace std;
int sum(int start, int cnt, int step = 1) {
    return (start * cnt) + cnt * (cnt - 1) * step / 2;
}
int main() {
    int n, k, s1, s2, c1;
    scanf("%d %d", &n, &k);
    c1 = n/k;
    s1 = sum(k, c1, k);
    s2 = sum(1, n) - s1;
    printf("%.1f %.1f", (s1 * 1.0) / c1, (s2 * 1.0) / (n - c1));
    return 0;
}