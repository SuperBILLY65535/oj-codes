#include <cstdio>
using namespace std;
int main() {
    long long n, output, fib[100];
    scanf("%lld", &n);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("%lld.00", fib[n]);
    return 0;
}