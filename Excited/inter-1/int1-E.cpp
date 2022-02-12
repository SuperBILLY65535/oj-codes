#include <map>
#include <string>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cstring>

int main() 
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    std::map<std::string, std::string> dic;
    std::string mar, eng;
    std::cin >> mar;
    while(std::cin >> eng && eng != "END")
    {
        std::cin >> mar;
        dic[mar] = eng;
    }

    std::string output, cur;
    std::cin >> cur;
    output.clear();
    cur.clear();

    char tmp;
    getchar();
    while(std::scanf("%c", &tmp) == 1)
    {
        if(isalnum(tmp)) cur += tmp;
        else
        {   // 单词读取结束
            if(dic.contains(cur))
            {
                output.append(dic[cur]);
            }
            else
            {
                output.append(cur);
            }
            cur.clear();
            output += tmp;
        }
        if(cur == "END") break;
    }
    std::cout << output;
    return 0;
}