#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-6;

double f(const double& x) {
    return x*x*x*x*8 + x*x*x*7 + x*x*2 + x*3 + 6;
}

bool equate(const double& a, const double& b) {
    return (abs(a - b) < eps);
}

double find_root(const double& y, const double& _l, const double& _r) {
    if((y >= f(0))  && (y <= f(100))) {
        double mid, l = _l, r = _r;
        while(!equate(l, r)) {
            mid = (l + r) / 2;
            if(equate(f(mid), y)) return mid;
            if(f(mid) > y) {
                r = mid - 1e-7;
            }
            else {
                l = mid + 1e-7;
            }
        }
    }
    else {
        return -1;
    }
}

int main() {
    unsigned T;
    double y, ans;
    cin >> T;
    while(T--) {
        cin >> y;
        if(equate(ans = find_root(y, 0, 100), -1)) {
            printf("No solution!\n");
        }
        else {
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}