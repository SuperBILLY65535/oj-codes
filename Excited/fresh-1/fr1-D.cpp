#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

unsigned pow(unsigned base, unsigned pow, unsigned modulus = 1000) {
    base %= modulus;
    if(base == 1) return 1;
    if(base == 0) return 0;
    unsigned ans = 1;
    while(pow > 0) {
        if(pow % 2) {
            ans *= base;
            ans %= modulus;
        }
        base = base * base % modulus;
        pow = pow >> 1;
    }
    return ans % modulus;
}

int main() {
    unsigned a, b;
    deque<unsigned> ans;
    ans.clear();
    while(cin >> a >> b) {
        if ((a == 0)&&(b == 0)) break;
        ans.push_back(pow(a, b));
    }
    for(unsigned i: ans) {
        cout << i << endl;
    }
    return 0;
}