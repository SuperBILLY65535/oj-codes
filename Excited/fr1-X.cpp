#include <iostream>

int main() {
    unsigned long long beef[40][3], n;
    beef[1][0] = beef[1][1] = beef[1][2] = 1;
    for(int i = 2; i < 40; i++)
    {
        beef[i][0] = beef[i - 1][0] + beef[i - 1][1] + beef[i - 1][2];
        beef[i][1] = beef[i - 1][0] + beef[i - 1][2];
        beef[i][2] = beef[i - 1][0] + beef[i - 1][1] + beef[i - 1][2];
    }
    while(std::cin >> n)
    {
        std::cout << beef[n][0] + beef[n][1] + beef[n][2] << '\n';
    }
    return 0;
}