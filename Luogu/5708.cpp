#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    double a,b,c,p;
    scanf("%f%f%f", &a, &b, &c);
    p=(a+b+c)/2;
    printf("%.1f", sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}