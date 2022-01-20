#include <iostream>

int main() {
    unsigned long long block[51];
    block[0] = 0; block[1] = 1; block[2] = 2;
    for(int i = 3; i < 51; i++) {
        block[i] = block[i - 1] + block[i - 2];
    }
    int n;
    while(std::cin >> n) std::cout << block[n] << '\n';
    return 0;
}