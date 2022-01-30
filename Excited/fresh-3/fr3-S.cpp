#include <cstdio>
#include <cstring>
#include <queue>

char map[200][200];
bool vis[200][200];
const int move[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

struct pos{
    int c, r, step; bool guard;
    void setv(const int &row, const int &col, const int &st)
    {
        c = col; r = row; step = st;
    }
    pos() = default;
    char &stat() const {return map[r][c];}
    bool checkvis() const {return vis[r][c];}
    void visit() {vis[r][c] = true;}
};

bool operator==(const pos &lhs, const pos &rhs)
{
    return (lhs.c == rhs.c && lhs.r == rhs.r);
}

bool within(const int &l, const int &m, const int &n) 
{
    return (l <= m && m <= n);
}

bool boundCheck(const pos &cur, const int &row, const int &col)
{   
    // checks if:
    // the position is legal
    // the position is not visited and not a wall
    if(within(0, cur.c, col-1) && within(0, cur.r, row-1))
    {
        if(!cur.checkvis() && cur.stat() != '#') return true;
    }
    return false;
}

void bfs(std::queue<pos> &st, const int &col, const int &row)
{
    pos cur, tmp;
    std::memset(vis, false, sizeof(vis));

    while(!st.empty())
    {
        cur = std::move(st.front()); 
        st.pop();

        if(cur.stat() == 'x' && !cur.guard) // guard not eliminated yet
        {
            cur.guard = true;
            cur.step++;
            st.push(cur);
            continue;
        }

        cur.guard = false;
        for(int i = 0; i < 4; i++) 
        {
            tmp.setv(cur.r + move[i][0], cur.c + move[i][1], cur.step + 1);
            if(boundCheck(tmp, row, col))
            {
                if(tmp.stat() == 'a')
                {
                    std::printf("%d\n", tmp.step);
                    return;
                }
                tmp.visit();
                st.push(tmp);
            }
        }
    }
    std::printf("Poor Dingba has to stay in the prison all his life.\n");
}

int main()
{
    int col, row; 
    pos begin;
    
    // freopen("q-in.txt", "r", stdin);
    while(std::scanf("%d %d", &row, &col) == 2)
    {
        std::queue<pos> st;
        for(int r = 0; r < row; r++)
        {
            scanf("%s", map[r]);
            for(int c = 0; c < col; c++)
            {
                if(map[r][c] == 'r')
                {
                    begin.setv(r, c, 0);
                    st.push(std::move(begin));
                }
            }
            std::scanf("\n");
        }
        bfs(st, col, row);
    }
    return 0;
} 