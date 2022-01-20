#include <iostream>
#include <algorithm>
#include <functional>

const int maxn = 1000;

int solve(int tianji[], int king[], int n){
    int draw = 0, t = 0, k = 0;
    while(k < n) {
        if(tianji[t] >= king[k]){
            t++;
            if(tianji[t] == king[k]) draw++;
        }
        k++;
    }
    n -= draw; t -= draw;
    return 200*(2*t-n);
}

int main() {
    int n, tianji[maxn], king[maxn];
    while(std::cin >> n) {
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            std::cin >> tianji[i];
        }
        std::sort(tianji, tianji + n, std::greater<int>());
        for(int i = 0; i < n; i++) {
            std::cin >> king[i];
        }
        std::sort(king, king + n, std::greater<int>());
        std::cout << solve(tianji, king, n) << std::endl;
    }
    return 0;
}