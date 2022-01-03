#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    int t = 0;
    while(n >= (++t)) {
        sum += t * t;
        n -= t;
    }
    sum += n * t;
    printf("%d", sum);
    return 0;
}