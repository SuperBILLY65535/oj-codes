#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef unsigned un;

un gcd(const un& lhs, const un& rhs) {
    return (rhs == 0)? lhs : gcd(rhs, lhs % rhs);
}

un lcm(const un& lhs, const un& rhs) {
    return max<un>(lhs, rhs) / gcd(lhs, rhs) * min(lhs, rhs);
}

int main() {
    unsigned n, k, l, tmp;
    std::cin >> n;
    deque<un> ans;
    while(n--) {
        cin >> k;
        l = 1;
        while(k--) {
            std::cin >> tmp;
            l = lcm(l, tmp);
        }
        ans.push_back(l);
    }
    for(auto i: ans) {
        cout << i << endl;
    }
    return 0;
}