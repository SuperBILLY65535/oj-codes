#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int maxcost = 2147483647, count, pack, price, cost;
    scanf("%d", &count);
    for(int i=0; i<3; i++) {
        scanf("%d%d", &pack, &price);
        cost = ceil(count * 1.0 / pack) * price;
        maxcost = fmin(maxcost, cost);
    }
    printf("%d", maxcost);
    return 0;
}