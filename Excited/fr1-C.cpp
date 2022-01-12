#include <iostream>
#include <deque>
using namespace std;

unsigned calc(unsigned num, unsigned pow, unsigned modulus = 10) {
    num %= modulus;
    if(num == 1) return 1;
    unsigned ans = 1;
    while(pow > 0) {
        if(pow % 2) {
            ans *= num;
            ans %= modulus;
        }
        num = num * num % modulus;
        pow = pow >> 1;
    }
    return ans % modulus;
}
int main() {
    unsigned n, k;
    std::deque<unsigned> ans;
    ans.clear();
    cin >> n;
    while(n--) {
        cin >> k;
        ans.push_back(calc(k, k));
    }
    for(auto i: ans) {
        cout << i << endl;
    }
    return 0;
}