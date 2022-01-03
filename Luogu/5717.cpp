#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int s[3];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &s[i]);
    }
    sort(&s[0], &s[3]);
    if (s[0] + s[1] <= s[2]) {
        printf("Not triangle");
        return 0;
    }
    if (s[2] == hypot(s[0], s[1])) {
        printf("Right triangle\n");
    }
    else {
        if (s[2]*1.0 > hypot(s[0], s[1])) {
            printf("Obtuse triangle\n");
        }
        else {
            printf("Acute triangle\n");
        }
    }
    if ((s[0] == s[1]) || (s[1] == s[2])) {
        printf("Isosceles triangle\n");
    }
    if (s[0] == s[2]) {
        printf("Equilateral triangle\n");
    }
    return 0;
}