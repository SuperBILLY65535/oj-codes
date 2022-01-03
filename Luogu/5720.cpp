#include <cstdio>
using namespace std;
int main() {
    int i, l;
    scanf("%d", &l);
    for(i = 1; l > 1; i++) {
        l = l / 2;
    }
    printf("%d", i);
    return 0;
}