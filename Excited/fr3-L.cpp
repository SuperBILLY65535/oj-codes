#include <cstdio>
#include <vector>

size_t nimSum(const std::vector<size_t> &num)
{
    size_t tmp = 0u;
    for(const auto &i: num)
    {
        tmp = i ^ tmp;
    }
    return tmp;
}

int main() {
    std::vector<size_t> req;
    size_t tmp;
    int count;
    while(std::scanf("%d", &count))
    {
        if(count == 0) break;
        req.clear();
        tmp = 0u;
        while(count--)
        {
            std::scanf("%u", &tmp);
            req.push_back(tmp);
        }
        tmp = nimSum(req);
        // std::printf("%d\n", tmp);
        if(tmp == 0) std::printf("Grass Win!\n");
        else std::printf("Rabbit Win!\n");
    }
    return 0;
}