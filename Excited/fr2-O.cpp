#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>

struct node{
    int cup[3], count;
    int &operator[] (size_t index)
    {
        return cup[index];
    }
};

bool mk[101][101];

bool mark(node &s)
{
    if(mk[s[1]][s[2]] == true) return false;
    else 
    {
        mk[s[1]][s[2]] = true;
        return true;
    }
}

bool flag(node &s, const int &cola)
{
    for(int i = 0; i < 3; i++)
        if(s[i%3] == s[(i+1)%3] && s[i] == cola / 2) 
            return true;

    return false;
}

void solve(const node& begin, int vol[])
{
    if(vol[0] % 2 != 0)
    {   // check if the total volume of cola is an odd number
        std::printf("NO\n");
        return;
    }

    // initialize
    std::deque<node> st;
    st.push_back(begin);
    std::memset(mk, 0, sizeof(mk));

    node tmp, cur; int delta;
    while(!st.empty())
    {
        cur = std::move(st.front());
        st.pop_front();
        for(int from = 0; from < 3; from++)
        for(int to = 0; to < 3; to++)
        if(from != to)
        {   //pour cola from cup[from] to cup[to]
            tmp = cur; 
            tmp.count++;

            delta = std::min(cur[from], vol[to] - cur[to]);
            tmp[from] -= delta; 
            tmp[to] += delta;

            if(flag(tmp, vol[0])) {
                std::printf("%d\n", tmp.count);
                st.clear();
                return;
            }
            if(mark(tmp))
            {
                st.push_back(tmp);
            }
        }
    }
    std::printf("NO\n");
    return;
}

int main()
{
    node tmp; tmp[1] = tmp[2] = tmp.count = 0;
    int v[3];
    while(std::scanf("%d %d %d", v, v+1, v+2) == 3)
    {
        if(v[0] == 0 && v[1] == 0 && v[2] == 0) break;
        tmp[0] = v[0];
        solve(tmp, v);
    }
    return 0;
}