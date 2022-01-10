#include <cstdio>
#include <cmath>
typedef unsigned long long ull;
const int max = 100001;
bool prime(ull k){
    static bool p[max] = {false, false, true};
    static ull tmp = 2;
    if (k<=tmp) return p[k];
    else {
        for(int i = 3; i <= std::sqrt(k); i+=2) {
            if (k % i == 0) {
                
            }
        }
    }
}
int main() {
    ull n;;
    std::scanf("%lld", &n);

}