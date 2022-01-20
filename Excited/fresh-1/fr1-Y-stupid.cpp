#include <iostream>

int main() {
    unsigned long long rgb[40][3][3] = 
    {
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        },
        {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        }
    };
    for(int i = 2; i < 40; i++)
    for(int j = 0; j < 3; j++)
    for(int k = 0; k < 3; k++)
        rgb[i][j][(j+k)%3]
        = rgb[i-1][j][(j+k+1)%3]
        + rgb[i-1][j][(j+k+2)%3];

    int n;
    while(std::cin >> n) 
        std::cout 
        << [&rgb] (int n) ->unsigned long long 
        {
            if(n == 1)return 3;
            unsigned long long sum = 0;
            for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            if(i != j) sum += rgb[n][i][j];
            return sum;
        }(n) 
        << '\n';
    return 0;
}