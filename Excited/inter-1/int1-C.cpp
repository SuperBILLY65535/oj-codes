#include <set>
#include <iostream>
#include <string>
// #define DEBUG

int main() 
{
    #ifndef DEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    std::set<std::string> books;
    std::string book;
    int count;
    while(std::cin >> count)
    {
        books.clear();
        while(count--)
        {
            std::cin >> book;
            books.emplace(book);
        }
        std::cout << books.size() << '\n';
    }
    return 0;
}