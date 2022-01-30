#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int ans[1001];
std::vector<int> op = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
std::queue<int> st;

void addn()
{   // add N-points
    int tmp;
    while(!st.empty())  // st saved the P-points last processed by addp()
    {
        tmp = st.front();
        for(const auto &i: op) 
        {
            if(tmp+i > 1000) break;
            ans[tmp+i] = 1; // marks that this is a N-point
        }
        st.pop();
    }
}

void addp()
{   // add P-points
    bool isp;
    for(int j = 0; j <= 1000; j++)
    {
        if(ans[j] != -1) continue;  // this point has been processed
        isp=true;   // isp for is P-point
        for(const auto &i: op)
        {   
            if(j - i < 0) break;
            if(ans[j-i] != 1) isp = false;  //not a P-point
        }
        if(isp)
        {   //is a P-point
            ans[j] = 0; //mark as a P-point
            st.push(j); //push for the next addn();
        }
    }
}

int main() {
    std::memset(ans, -1, sizeof(ans));
    ans[0] = 0;
    st.push(0);
    while(!st.empty())
    {   // an empty queue marks that no more points can be identified
        addn();
        addp();
    }

    //debugging
    // for(auto i: ans) std::printf("%d ", i);
    
    int m, n, p, a;
    while(std::scanf("%d %d %d", &m, &n, &p))
    {
        if(m == 0 && n ==0 && p == 0) break;
        a = ans[m] + ans[n] + ans[p];
        if(a % 2 == 1) std::printf("Fibo\n");
        else std::printf("Nacci\n");
    }
    return 0;
}