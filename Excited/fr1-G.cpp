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
food makeFood(int c, int b) {
    food tmp;
    tmp.catFood = c; tmp.beans = b;
    return tmp;
}
struct sorter{
    bool operator() (const food& a, const food& b) {
        return a.price() < b.price();
    }
};

double solve(double catFood, std::deque<food> &vault) {
    // std::sort(vault.front(), vault.back(), sorter());
    double beans = 0;
    while(!vault.empty() && (catFood > 0)) {
        if(catFood >= vault.front().catFood) {
            catFood -= vault.front().catFood;
            beans += vault.front().beans;
            vault.pop_front();
        }
        else {
            beans += vault.front().price() * catFood;
            catFood = 0;
            vault.clear();
        }
    }
    return beans;
}

int main() {
    int m, n;
    std::deque<food> que;
    while(std::cin>> m >> n) {
        que.clear();
        if((m == -1) & (n == -1)) break;
        int k = n, bean, food;
        while(k--) {
            std::cin >> bean >> food;
            que.push_back(makeFood(food, bean));
        }
        std::cout << std::setprecision(3) << solve(food, que) << std::endl;
    }
    return 0;
}