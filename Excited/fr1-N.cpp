#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <deque>

struct node
{
    unsigned depth;
    node* fa;
    void init() 
    {
        depth = 1;
        fa = this;
    }
    node *grandfa() 
    {
        if(fa == this) return this;
        else return fa->grandfa();
    }
};

bool query(node &a, node &b) 
{
    return (a.grandfa() == b.grandfa());
}

void unite(node &a, node &b) 
{
    if(a.grandfa()->depth == b.grandfa()->depth) 
    {
        node *tmp = b.grandfa();
        a.grandfa()->fa = tmp;
        tmp->depth++;
    }
    else
    {
        if(a.depth < b.depth) 
        {
            a.grandfa()->fa = b.grandfa();
        }
        else 
        {
            b.grandfa()->fa = a.grandfa();
        }
    }
}

struct road
{
    int price;
    node *begin, *end;
};

node villages[101];

void solve(std::deque<road> roads) 
{
    int sum = 0;
    std::sort(roads.begin(), roads.end(), 
        [] (const road &lhs, const road &rhs) ->bool {
            return lhs.price < rhs.price;
        });
    while(!roads.empty()) 
    {
        if(!query
        (
            *(*roads.begin()).begin,
            *(*roads.begin()).end
        )){
            unite
            (
            *(*roads.begin()).begin,
            *(*roads.begin()).end
            );
            sum += (*roads.begin()).price;
        }
        roads.pop_front();
    }
    std::cout << sum << '\n';
    return;
}

int main()
{
    
    road tmp;
    std::deque<road> roads;
    int n, x, y;
    while(std::cin >> n) 
    {
        if(n == 0) break;
        roads.clear();
        for(int i = 1; i <= n; i++) villages[i].init();
        while(n--) 
        {
            std::cin >> x >> y >> tmp.price;
            tmp.begin = &villages[x]; tmp.end = &villages[y];
            roads.push_back(tmp);
        }
        solve(roads);
    }
    return 0;
}