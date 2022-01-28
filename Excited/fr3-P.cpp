#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

const int maxn = 10001;

int s[maxn];
std::vector<int> opr;

void calc_sg(const int &m)
{
    int pred[maxn];
    for(int i = 0; i <= m; i++)
    {
        // if(s[i] != -1) continue;
        if(i < opr.front()) 
        {
            s[i] = 0;
            continue;
        }
        else 
        {
            std::memset(pred, 0, sizeof(int) * (opr.size()+1));
            for(const int &op: opr)
            {
                if(i - op >= 0) pred[s[i-op]] = 1;
                else break;
            }
            for(int j = 0; ; j++) if(pred[j] == 0)
            {
                s[i] = j;
                break;
            }
        }
    }
}

// size_t nimSum(const std::vector<size_t> &num)
// {
//     size_t tmp = 0u;
//     for(const auto &i: num)
//     {
//         tmp = i ^ tmp;
//     }
//     return std::move(tmp);
// }

int main()
{
    int n, tmp, cnt, beads;
    while(std::scanf("%d", &n) == 1)
    {
        if(n == 0) break;   // end of input

        //initialize
        opr.clear();
        std::memset(s, -1, maxn);
        
        //get operands
        while(n--)
        {
            std::scanf("%d", &tmp);
            opr.emplace_back(std::move(tmp));
        }
        std::sort(opr.begin(), opr.end());

        calc_sg(maxn);

        // for each test case see if losing or winning
        std::scanf("%d", &n);
        while(n--)
        {
            // beads.clear();
            beads = 0;
            std::scanf("%d", &cnt);
            while(cnt--) 
            {
                std::scanf("%d", &tmp);
                // beads.emplace_back(s[tmp]);
                beads = beads ^ s[tmp];
            }
            if(beads == 0) std::printf("L");
            else std::printf("W");
        }
        std::printf("\n");
    }
    return 0;
}