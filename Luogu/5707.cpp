#include <cstdio>
#include <cmath>
using namespace std;
void output(int t) {
	int h=t/60, m=t%60;
	printf("%.2d:%.2d", h, m);
} 
int main() {
	int s,v,time=470;
	scanf("%d%d", &s, &v);
	time -= ceil(1.0*s/v);
	if(time<0) {time += 24*60;}
	output(time);
	return 0;
}