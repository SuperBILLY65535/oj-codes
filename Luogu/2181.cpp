#include <cstdio>
using namespace std;

unsigned long long calc(unsigned long long n) {
    unsigned long long sum = 0;
    for (unsigned long long i=0; i<n-1; i++) {
        sum += i*(n-i-2);
    }
    return sum/2*n/2;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long ans = calc(n);
    printf("%llu", ans);
    return 0;
}