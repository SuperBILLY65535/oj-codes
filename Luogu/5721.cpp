#include <cstdio>
using namespace std;
int main() {
    int num = 1, s;
    scanf("%d", &s);
    for(int col = 1; col <= s; col++) {
        for(int line = 1; line <= s - col + 1; line++) {
            printf("%.2d", num++);
        }
        printf("\n");
    }
    return 0;
}