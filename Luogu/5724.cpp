#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, a, max = 0x80000000, min = 0x7fffffff;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        max = fmax(max, a);
        min = fmin(min, a);
    }
    printf("%d", max - min);
    return 0;
}