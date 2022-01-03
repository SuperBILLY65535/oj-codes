#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    return ((b == 0)? a : gcd(b, a % b));
}
int main() {
    int s[3];
    scanf("%d%d%d", &s[0], &s[1], &s[2]);
    sort(&s[0], &s[3]);
    int g = gcd(s[0], s[2]);
    printf("%d/%d", s[0]/g, s[2]/g);
    return 0;
}