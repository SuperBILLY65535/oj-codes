#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

char map[8][8]; bool vis[8][8];

struct pos{
    int r, c, step;
    void setv(int _r, int _c, int _s)
    {
        r = _r; c = _c; step = _s;
    }
    char &stat() const {
        return map[r][c];
    }
};

bool operator== (const pos &lhs, const pos &rhs)
{
    return (lhs.r == rhs.r && lhs.c == rhs.c && lhs.step == rhs.step);
}

const int move[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool within(const int &l, const int &m, const int &n) 
{
    return (l <= m && m <= n);
}

bool boundCheck(const pos &cur, const pos &size)
{
    if(within(0, cur.r, size.r)
    && within(0, cur.c, size.c))
    {
        if(!vis[cur.r][cur.c] 
        && cur.stat() != 'X') 
            return true;
    }
    return false;
}

bool dfs(const pos &cur, const pos &end, const pos &sz)
{
    if(cur == end) return true;
    pos tmp; 
    for(int i = 0; i < 4; i++) 
    {
        tmp.setv(
            cur.r + move[i][0],
            cur.c + move[i][1],
            cur.step + 1
        );
        if(boundCheck(tmp, sz))
        {
            vis[tmp.r][tmp.c] = true;
            if(dfs(tmp, end, sz))
                return true;
            vis[tmp.r][tmp.c] = false;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // std::ifstream test_in("in.txt");

    int row, col, time;
    pos begin, end, sz;
    // while(test_in >> row >> col >> time)
    while(std::cin >> row >> col >> time)
    { 
        if(row == 0 && col == 0 && time == 0) break;

        std::memset(vis, 0, sizeof(vis));
        sz.setv(row - 1, col - 1, 0);
        for(int r = 0; r < row; r++)
        {
            std::cin >> map[r];
            for(int c = 0; c < col; c++)
            {
                if(map[r][c] == 'S')
                    begin.setv(r, c, 0);
                if(map[r][c] == 'D')
                    end.setv(r, c, time);
            }
        }
        if(dfs(begin, end, sz)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;
}