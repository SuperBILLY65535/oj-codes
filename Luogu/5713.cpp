#include <cstdio>
using namespace std;
int main(){
	int n;
    scanf("%d", &n);
    if (n < 6) {
        printf("Local");
    }
    else {
        printf("Luogu");
    }
    return 0;
}