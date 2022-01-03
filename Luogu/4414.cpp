#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n[3];
    char s[3];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &n[i]);
    }
    scanf("\n");//可还行
    for(int i = 0; i < 3; i++) {
        scanf("%c", &s[i]);
    }
    sort(n, n+3);
    for(int i = 0; i < 3; i++) {
        printf("%d ", n[s[i] - 'A']);
    }
    return 0;
}