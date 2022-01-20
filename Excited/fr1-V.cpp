#include <iostream>

int main() {
    int blocks[31], n, c;
    blocks[1] = 1; blocks[2] = 3; 
    for(int i = 3; i < 31; i++) blocks[i] = blocks[i - 1] + 2 * blocks[i - 2];
    for(std::cin >> c; c > 0; c--) 
    {
        std::cin >> n;
        std::cout << blocks[n] << '\n';
    }
    return 0;
}