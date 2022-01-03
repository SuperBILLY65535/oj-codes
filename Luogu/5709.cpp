#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int m,t,s;
    scanf("%d%d%d", &m, &t, &s);
    if(t==0) {
        printf("%d", 0);
    } else {
        double ans=(double)(m)-(double)(s)/t;
        if(ans<=0) {
            printf("%d", 0);
        } else {
            printf("%d", (int)ans);
        }
    }
    return 0;
}