#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    double t, p;
    int n;
    scanf("%lf%d", &t, &n);
    p=t/n;
    printf("%.3f\n%d", p, n*2);
    return 0;
}   