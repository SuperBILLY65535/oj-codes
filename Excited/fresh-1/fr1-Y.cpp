#include <iostream>

int main()
{
    unsigned long long n, rgb[51] = {0, 3, 6, 6};
    for(int i = 4; i < 51; i++) {
        rgb[i] = rgb[i-1] + 2*rgb[i-2];
    }
    while(std::cin >> n)std::cout << rgb[n] << '\n';
    return 0;
}