#include <iostream>
#include <cstring>

char map[100][100];
bool vis[100][100];
int row, col;
const int move[8][2] = {
    {0, 1}, 
    {1, 1}, 
    {1, 0}, 
    {1, -1}, 
    {0, -1}, 
    {-1, -1}, 
    {-1, 0}, 
    {-1, 1}
};

bool within(const int &l, const int &m, const int &n) 
{
    return (l <= m && m < n);
}

bool flag(const int &r, const int &c)
{
    if(within(0, r, row) && within(0, c, col))
    {
        if(map[r][c] == '@' && !vis[r][c]) return true;
    }
    return false;
}

void mark(const int &r, const int &c)
{
    vis[r][c] = true;
    for(int i = 0; i < 8; i++)
    if(flag(
        r + move[i][0],
        c + move[i][1]
    ))
    {
        mark(r + move[i][0], c + move[i][1]);
    }
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans;

    while(std::cin >> row >> col)
    {
        if(col == 0 && row == 0) break;

        ans = 0;
        for(int r = 0; r < row; r++)
        {
            std::cin >> map[r];
        }
        std::memset(vis, false, sizeof(vis));

        for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
        if(map[r][c] == '@' && !vis[r][c])
        {
            ans++;
            mark(r, c);
        }

        std::cout << ans << '\n';
    }
    return 0;
}