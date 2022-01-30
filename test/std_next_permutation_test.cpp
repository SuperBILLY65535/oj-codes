#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<int> a = {1, 2, 3};
    do
    {
        for (auto &&i : a)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    } while (std::next_permutation(a.begin(), a.end()));
    return 0;
}