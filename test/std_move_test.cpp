#include <utility>
#include <queue>
#include <iostream>

int main() 
{
    std::queue<int> q;
    q.push(1);q.push(2);
    int a = std::move(q.front());
    q.pop();
    std::cout << q.size() << a;
    return 0;
}