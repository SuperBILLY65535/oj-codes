#include <cstdio>
using namespace std;

int main() {
    long long a[3];
    scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
    auto swap = [] (long long & a, long long & b) ->void {
        a = a + b;
        b = a - b;
        a = a - b;
    };
    if (a[0]>a[1]) {swap(a[0], a[1]);}
    if (a[0]>a[2]) {swap(a[0], a[2]);}
    if (a[1]>a[2]) {swap(a[1], a[2]);}
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}