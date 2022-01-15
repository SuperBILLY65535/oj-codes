#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>

struct food {
    int catFood, beans;
    double price() const {
        return catFood * 1.0 / beans;
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

double solve(double catFood, food* vault, unsigned size) {
    std::sort(vault, vault + size);
    unsigned i = 0;
    double beans = 0;
    while((i < size) && (catFood > vault[i].catFood)) {
        catFood -= vault[i].catFood;
        beans += vault[i].beans;
        i++;
    }
    if(i < size) {
        beans += vault[i].price() * catFood;
        catFood = 0;
    }
    return beans;
}

int main() {
    int m, n;
    food que[1001];
    while(std::cin>> m >> n) {
        if((m == -1) & (n == -1)) break;
        int k = n, beans, catFood;
        while(k--) {
            std::cin >> beans >> catFood;
            que[k] = makeFood(catFood, beans);
        }
        std::cout << std::setprecision(3) << solve(m, que, n) << std::endl;
    }
    return 0;
}