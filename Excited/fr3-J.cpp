#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int ans[1025];
std::vector<int> op = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400};
std::queue<int> st;

void addn()
{
    int tmp;
    while(!st.empty())
    {
        tmp = st.front();
        for(const auto &i: op) 
        {
            if(tmp+i > 1024) break;
            ans[tmp+i] = 1;
        }
        st.pop();
    }
}

void addp()
{
    bool isp;
    for(int j = 0; j <= 1024; j++)
    {
        if(ans[j] != -1) continue;
        isp=true;
        for(const auto &i: op)
        {
            if(j - i < 0) break;
            if(ans[j-i] != 1) isp = false;
        }
        if(isp)
        {
            ans[j] = 0;
            st.push(j);
        }
    }
}

int main() {
    st.push(0);
    std::memset(ans, -1, sizeof(ans));
    ans[0] = 0;
    while(!st.empty())
    {
        addn();
        addp();
    }
    int req;
    while(std::scanf("%d", &req) ==1)
    {
        if(ans[req] == 1) std::printf("Kiki\n");
        else std::printf("Cici\n");
    }
    return 0;
}