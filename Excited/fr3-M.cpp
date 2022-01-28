#include <cstdio>
#include <vector>
#include <utility>

size_t nimSum(const std::vector<size_t> &num)
{
    size_t tmp = 0u;
    for(const auto &i: num)
    {
        tmp = i ^ tmp;
    }
    return std::move(tmp);
}

size_t lowbit(const size_t &k)
{
    return k & -k;
}

size_t highbit(size_t k)
{
    size_t tmp = 0;
    while(k > 0)
    {
        tmp = lowbit(k);
        k -= tmp;
    }
    return std::move(tmp);
}

int main()
{
    std::vector<size_t> req;
    int count;
    size_t tmp, ans;

    while(std::scanf("%d", &count))
    {
        if(count == 0) break;
        req.clear();
        while(count--) 
        {
            std::scanf("%d", &tmp);
            req.push_back(std::move(tmp));
        }
        tmp = nimSum(req);

        if(tmp == 0) 
        {
            std::printf("0\n");
            continue;
        }
        ans = 0;
        tmp = highbit(tmp);
        
        for(auto &i: req)
        {
            i /= tmp;
            if(i%2) ans++;
        }
        std::printf("%u\n", ans);
    }
    return 0;
}