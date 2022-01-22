#include <deque>

struct node{
    size_t _depth;
    node* fa;
    node() 
    {
        init();
    }
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
        for(int i = 0; i < n; i++) nodes[i].init();
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