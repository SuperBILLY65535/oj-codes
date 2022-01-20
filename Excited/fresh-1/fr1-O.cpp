#include <deque>
#include <iostream>
#include <algorithm>

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
        for(auto &i: nodes) i.init();
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
            if(nodes[a].dp() < nodes[b].dp()) 
                nodes[a].grandfa()->fa = nodes[b].grandfa();
            else nodes[b].grandfa()->fa = nodes[a].grandfa();
        }
    }
    node &operator[] (const size_t &index)
    {
        return nodes[index-1];
    }
    bool check_connectivity() {
        node *t = nodes[1].grandfa();
        for(size_t i = 1; i < nodes.size(); i++) 
        {
            if(nodes[i].grandfa() != t) return false;
        }
        return true;
    }
};

struct edge{
    int begin, end, weight;
};
bool operator<(const edge& lhs, const edge& rhs)
{
    return lhs.weight < rhs.weight;
}

ufs graph;
std::deque<edge> edges;

int get_mst_weight()
{
    int sum = 0;
    std::sort(edges.begin(), edges.end());
    while(!edges.empty())
    {
        if(!graph.query(edges.front().begin, edges.front().end))
        {
            sum += edges.front().weight;
            graph.unite(edges.front().begin, edges.front().end);
        }
        edges.pop_front();
    }
    return sum;
}

int main() 
{
    int n, m;
    edge t;
    edges.clear();
    while(std::cin >> n >> m)
    {
        if(n == 0) break;
        graph.init(m + 1);
        while(n--) 
        {
            std::cin >> t.begin >> t.end >> t.weight;
            edges.push_back(t);
        }
        int ans = get_mst_weight();
        if (graph.check_connectivity()) std::cout << ans;
        else std::cout << '?';
        std::cout << '\n';
    }
    return 0;
}