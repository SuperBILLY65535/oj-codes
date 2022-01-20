#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstring>

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
}nodes[100001];

bool used[100001];

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

struct pair
{
    int a, b;
};

void solve(std::deque<pair> roads)
{
    for(int i = 1; i < 100001; i++) 
    {
        nodes[i].init();
    }
    for(auto i: roads)
    {
        if(query(nodes[i.a], nodes[i.b])) 
        {
            std::printf("No\n");
            return;
        }
        else
        {
            unite(nodes[i.a], nodes[i.b]);
        }
    }
    node *flag = nullptr;
    for(int i = 1; i < 100001; i++) if(used[i])
    {
        if(flag == nullptr) flag = nodes[i].grandfa();
        else
        {
            if(nodes[i].grandfa() != flag)
            {
                std::printf("No\n");
                return;
            }
        }
    }
    std::printf("Yes\n");
    return;
}

int main() 
{
    pair tmp;
    std::deque<pair> roads;
    std::memset(used, 0, sizeof(used));
    while(std::scanf("%d %d", &tmp.a, &tmp.b))
    {
        if((tmp.a == -1) && (tmp.b == -1)) break;
        if((tmp.a == 0) && (tmp.b == 0))
        {
           solve(roads);
           roads.clear();
           std::memset(used, 0, sizeof(used));
        //    std::scanf("\n");
        }
        else {
            roads.push_back(tmp);
            used[tmp.a] = used[tmp.b] = true;
        }
    }
    return 0;
}