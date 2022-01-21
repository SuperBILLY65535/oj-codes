#include <iostream>
#include <algorithm>
#include <deque>

int main() 
{
    int n, t; 
    std::deque<int> missiles, len;
    while(std::cin >> n)
    {
        missiles.clear();
        len.resize(n);
        while(n--) {
            std::cin >> t;
            missiles.push_back(t);
        }
        for(int i = 0; i < missiles.size(); i++) {
            
        }
    }
}