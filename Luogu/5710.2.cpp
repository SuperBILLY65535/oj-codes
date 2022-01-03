#include <cstdio>
using namespace std;
int main() {
	int x;
	scanf("%d", &x);
	bool a = (x % 2 == 0), b = (x > 4) && (x <= 12);
	printf("%d %d %d %d", a && b, a || b, (a && !b) || (!a && b), !(a || b));
	return 0;
}