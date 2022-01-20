#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <deque>

struct node{
    size_t _depth;
    node* fa;
    void init() 
    {
        _depth = 1;
        fa = this;
    }
    node *grandfa() 
    {
        if(fa == this) return this;
        else return fa->grandfa();
    }
    size_t &dp()
    {
        return grandfa()->_depth;
    } 
};

struct ufs{
    std::deque<node> nodes;
    void init(size_t n)
    {
        nodes.resize(n);
        for(size_t i = 0; i < n; i++) nodes[i].init();
    }
    bool query(const size_t &a, const size_t &b)
    {
        return nodes[a].grandfa() == nodes[b].grandfa();
    }
    void unite(const size_t &a, const size_t &b)
    {
        if(nodes[a].dp() == nodes[b].dp())
        {
            nodes[a].grandfa()->fa = nodes[b].grandfa();
            nodes[b].dp()++;
        }
        else
        {
            if(nodes[a].dp() < nodes[b].dp()) nodes[a].grandfa()->fa = nodes[b].grandfa();
            else nodes[b].grandfa()->fa = nodes[a].grandfa();
        }
    }
};

struct road{
    int begin, end, cost;
};
bool operator<(const road& lhs, const road& rhs)
{
    return lhs.cost < rhs.cost;
}

ufs villages;
std::deque<road> roads;

void solve()
{
    unsigned sum = 0;
    std::sort(roads.begin(), roads.end());
    while(!roads.empty())
    {
        if(!villages.query(roads.front().begin, roads.front().end))
        {
            sum += roads.front().cost;
            villages.unite(roads.front().begin, roads.front().end);
        }
        roads.pop_front();
    }
    std::cout << sum << '\n';
    return;
}

int main()
{
    road tmp;
    int n;
    while(std::cin >> n)
    {
        if(n == 0) break;
        villages.init(n + 1);
        roads.clear();
        for(int i = n*(n-1)/2; i > 0; i--)
        {
            std::cin >> tmp.begin >> tmp.end >> tmp.cost;
            roads.push_back(tmp);
        }
        solve();
    }
    return 0;
}