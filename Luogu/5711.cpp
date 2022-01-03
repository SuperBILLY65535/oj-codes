#include <cstdio>
using namespace std;
int main() {
	long long x;
	scanf("%lld", &x);
	bool res = [](long long a) {
		if(a % 4 != 0) {
			return false;
		}
		else {
			if(a % 100 != 0) {
				return true;
			}
			else {
				if(a % 400 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}(x);
	printf("%d", res);
	return 0;
}