#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int a, n, m = 0x7fffffff;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        m = fmin(a, m);
    }
    printf("%d", m);
    return 0;
}