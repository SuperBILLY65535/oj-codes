#include <iostream>
#include <algorithm>

template<class T>
T gcd(const T &x, const T &y) {
    return (y == 0)? x : gcd(y, x % y);
}

template<class T>
T lcm(const T &x, const T &y) {
    return std::max<T>(x, y) / gcd<T>(x, y) * std::min<unsigned>(x, y);
}


int main() {
    unsigned a, b;
    while(std::cin >> a >> b){
        std::cout << lcm<unsigned>(a, b) << std::endl;
    }
    return 0;
}