#include <iostream>

int main() {
    int sect[10001], n, c;
    sect[1] = 2;
    for(int i = 2; i < 10001; i++)
    {
        sect[i] = sect[i - 1] + 4 * (i - 1) + 1;
    }
    std::cin >> c;
    while(c--) 
    {
        std::cin >> n;
        std::cout << sect[n] << '\n';
    }
    return 0;
}