#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    const unsigned int k = (1 << n) - 1;
    for(unsigned int i = 0; i < (1 << n); i++) {
        for(unsigned int j = 0; j < (1 << n); j++) {
            if((i | j) == k) {printf("1 ");}
            else {printf("0 ");}
        }
        printf("\n");
    }
    return 0;
}