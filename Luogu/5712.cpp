#include <cstdio>
using namespace std;
int main() {
	int x;
	scanf("%d", &x);
	printf("Today, I ate %d apple", x);
	if(x > 1) {
		printf("s.");
	}
	else {
		printf(".");
	}
	return 0;
}