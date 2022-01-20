#include <iostream>

int main() 
{
    int tile[31], t, n;
    tile[1] = 1; tile[2] = 3;
    for(int i = 3; i < 31; i++)
    {
        tile[i] = tile[i - 1] + 2 * tile[i - 2];
    }
    for(std::cin >> t; t > 0; t--) 
    {
        std::cin >> n;
        std::cout << tile[n] << '\n';
    }
    return 0;
}