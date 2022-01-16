#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>

struct food {
    int catFood, beans;
    double price() const {
        return 1.0 * catFood / beans;
    }
};
food makeFood(int catFood, int beans) {
    food tmp;
    tmp.catFood = catFood; tmp.beans = beans;
    return tmp;
}

bool operator< (const food& lhs, const food& rhs) {
    if(lhs.catFood == 0){
        if(rhs.catFood == 0) {
            return (lhs.beans < rhs.beans);
        }
        else return true;
    }
    else {
        if(rhs.catFood == 0) {
            return false;
        }
        else return lhs.price() < rhs.price();
    }
}

double solve(double catFood, food vault[], unsigned size) {
    if(size == 0) return 0;
    std::sort(vault, vault + size);
    unsigned i = 0;
    double beans = 0;
    while((i < size) && (catFood > vault[i].catFood)) {
        catFood -= vault[i].catFood;
        beans += vault[i].beans;
        i++;
    }
    if(i < size) {
        beans += (catFood * vault[i].beans * 1.0 / vault[i].catFood);
        catFood = 0;
    }
    return beans;
}

int main() {
    int m, n;
    food que[1001];
    while(std::cin>> m >> n) {
        if((m == -1) & (n == -1)) break;
        int k = n, beans, catFood, freeBeans = 0, i = 0;
        while(k--) {
            std::cin >> beans >> catFood;
            if(catFood != 0) que[i++] = makeFood(catFood, beans);
            else {
                freeBeans += beans;
                n--;
            }
        }
        // std::printf("%.3f\n", solve(m, que, n));
        double ans = solve(m, que, n) + freeBeans;
        ans *= 1000; ans = (int)(ans + 0.5); ans/=1000;
        std::printf("%.3lf\n", ans);
    }
    return 0;
}