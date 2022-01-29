#include <cstdio>
#include <cstring>
#include <deque>
#include <utility>

const int move[8][2] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

struct node{
    int col, row, count;
    node() = default;
    void setv(const int &c, const int &r, const int &cnt)
    {
        col = c; row = r; count = cnt;
    }
};

bool operator== (const node& lhs, const node& rhs)
{
    return (lhs.col == rhs.col && lhs.row == rhs.row);
}

bool within(const int &l, const int &m, const int &n) 
{
    return (l <= m && m <= n);
}

int bfs(const node &begin, const node &end)
{
    if(begin == end) return 0;
    static std::deque<node> stat;
    node cur, tmp;
    stat.clear();
    stat.push_back(begin);
    while(!stat.empty())
    {
        cur = std::move(stat.front()); 
        stat.pop_front();

        for(int m = 0; m < 8; m++)
        {
            if(within(1, cur.col + move[m][0], 8)
            && within(1, cur.row + move[m][1], 8))
            {
                tmp.setv(
                    cur.col + move[m][0], 
                    cur.row + move[m][1], 
                    cur.count + 1
                );
                if(tmp == end) return tmp.count;
                stat.push_back(std::move(tmp));
            }
        }
    }
    return -1;  
    // for safety checks
    // actually when -1 occurs the process is wrong
}

int main()
{
    int row[2]; char col[2]; node b, e;
    while(std::scanf("%c%d %c%d\n", col, row, col+1, row+1) == 4)
    {
        b.col = col[0] - 96; b.row = row[0]; b.count = 0;
        e.col = col[1] - 96; e.row = row[1]; 
        std::printf("To get from %c%d to %c%d takes %d knight moves.\n",
            col[0], row[0], col[1], row[1],
            bfs(b, e)
        );
    }
    return 0;
}