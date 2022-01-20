#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

void yes() {std::cout << "yes\n";}
void no() {std::cout << "no\n";}

void solve(int *deg, int size)
{
    std::sort(deg, deg + size, std::greater<int>());
    if(*deg >= size)
    {
        no();
        return;
    }
    if(*deg > 0) 
    {
        for(int i = 1; i <= *deg; i++) 
        {
            deg[i]--;
            if(deg[i] < 0) 
            {
                no();
                return;
            }
        }
        solve(deg + 1, size - 1);
        return;
    }
    else
    {
        for(int i = 0; i < size; i++) 
        {
            if(deg[i] < 0) 
            {
                no();
                return;
            }
        }
        yes();
    }
}

int main() 
{
    int tests, nodes, deg[1001];
    std::cin >> tests;
    while(tests--) 
    {
        std::cin >> nodes;
        for(int i = 0; i < nodes; i++) 
        {
            std::cin >> deg[i];
        }
        solve(deg, nodes);
    }
    return 0;
}