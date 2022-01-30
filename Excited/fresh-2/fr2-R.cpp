#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

bool map[51][51][51]; 
bool vis[51][51][51];

const int move[6][3] = { // moves
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, -1}, 
    {0, 0, 1}
};

struct pos
{
    int h, l, w, t;
    void setv(const int &_h, const int &_l, const int &_w, const int &_t)
    {
        h = _h; l = _l; w = _w; t = _t;
    }
    void visit()
    {
        vis[h][l][w] = true;
    }
};

bool within(const int &l, const int &m, const int &r) 
{
    return (l <= m && m <= r);
}

bool boundcheck(const pos &cur, const pos &end)
{
    if(within(0, cur.h, end.h)
    && within(0, cur.l, end.l)
    && within(0, cur.w, end.w))
    {
        if(!vis[cur.h][cur.l][cur.w] 
        && !map[cur.h][cur.l][cur.w]) 
            return true;
    }
    return false;
}

bool operator== (const pos &lhs, const pos &rhs)
{
    return (lhs.h == rhs.h && lhs.l == rhs.l && lhs.w == rhs.w);
}

void solve(const pos &door, const int &time)
{
    pos cur, tmp;
    std::queue<pos> st; // 状态队列
    tmp.setv(0,0,0,0);
    if(tmp == door)
    {   // 特判
        std::printf("0\n");
        return;
    }
    tmp.visit();
    st.push(std::move(tmp));
 
    std::memset(vis, 0, sizeof(vis));

    while(!st.empty())
    {
        cur = std::move(st.front());
        st.pop();

        if(cur.t > time) break;
        for(int i = 0; i < 6; i++)
        {   // tmp存储下一个状态
            tmp.setv(
                cur.h + move[i][0],
                cur.l + move[i][1],
                cur.w + move[i][2],
                cur.t + 1
            );
            if(boundcheck(tmp, door))
            {
                if(tmp == door)
                {
                    std::printf("%d\n", tmp);
                    return;
                }
                tmp.visit();
                st.push(std::move(tmp));
            }
        }
    }
    std::printf("-1\n");
}

int main()
{
    int tests, height, width, length, tmp, time; pos end;
    // freopen("in.txt", "r", stdin);
    for(std::scanf("%d", &tests); tests>0; tests--)
    {
        std::scanf("%d %d %d %d\n", &height, &length, &width, &time);
        for(int h = 0; h < height; h++)
        for(int l = 0; l < length; l++)
        for(int w = 0; w < width; w++)
            std::scanf("%d", &map[h][l][w]);

        end.setv(height - 1, length - 1, width - 1, 0);
        solve(end, time);
    }
    return 0;
}