#include <cstdio>
#include <functional>
#include <algorithm>
#include <deque>
#include <cstring>

struct pie{
    int time, loc;
};

int main() 
{
    std::deque<pie> pies;
    std::function<bool(pie, pie)> cmp = 
        [] (const pie& lhs, const pie& rhs) ->bool
        {
            return lhs.time > rhs.time;
        };
    int n, dp[2][11]; pie t;
    while(std::scanf("%i", &n))
    {
        if(n==0)break;

        pies.clear();
        std::memset(dp, 0, sizeof(dp));

        while(n--) 
        {
            std::scanf("%i %i", &t.loc, &t.time);
            pies.push_back(t);
        }
        std::sort(pies.begin(), pies.end(), cmp);

        int time = pies.front().time;
        while(time>=0)
        {
            dp[time%2][0] = std::max(
                dp[(time+1)%2][0], 
                dp[(time+1)%2][1]
            );
            for(int i = 1; i < 10; i++)
            {
                dp[time%2][i] = std::max({
                    dp[(time+1)%2][i-1],
                    dp[(time+1)%2][i],
                    dp[(time+1)%2][i+1]
                });
            }
            dp[time%2][10] = std::max(
                dp[(time+1)%2][9], 
                dp[(time+1)%2][10]
            );

            while(time == pies.front().time) 
            {
                dp[time%2][pies.front().loc]++;
                pies.pop_front();
            }

            time--;
        }
        std::printf("%i\n", dp[0][5]);
    }
    return 0;
}