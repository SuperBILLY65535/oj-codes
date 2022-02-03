#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <deque>

int main()
{
    std::string i, o;
    int count;
    std::vector<std::string> op;
    std::stack<char> tr;
    while(std::cin >> count)
    {
        op.clear();
        while(!tr.empty()) tr.pop();

        std::cin >> i >> o;
        char tmp;

        auto icur = i.begin(), ocur = o.begin();
        while(icur != i.end())
        {   // 第一次循环, 让所有的火车均入队列
            if(!tr.empty() && tr.top() == *ocur)
            {   // 如果需要弹出就当场弹出
                tr.pop();
                op.push_back("out");
                ocur++;
                continue;
            }
            tr.push(*icur);
            op.push_back("in");
            icur++;
        }
        while(ocur != o.end() && *ocur == tr.top())
        {   // 第二次循环, 对于还在队列里的火车, 依次弹出
            tr.pop();
            op.push_back("out");
            ocur++;
        }
        if(!tr.empty())
        {   // tr非空即代表无法实现
            std::cout << "No.\n";
        }
        else
        {
            std::cout << "Yes.\n";
            for(const auto &i: op) std::cout << i << '\n';
        }
        std::cout << "FINISH\n";
    }
    return 0;
}