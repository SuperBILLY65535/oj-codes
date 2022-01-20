#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

struct node{
    unsigned depth;
    node* fa;
    void init() {
        depth = 1;
        fa = this;
    }
    node *grandfa() {
        if(fa == this) return this;
        else return fa->grandfa();
    }
};

bool query(node &a, node &b) {
    return (a.grandfa() == b.grandfa());
}
void unite(node &a, node &b) {
    if(!query(a,b)){
        if(a.grandfa()->depth == b.grandfa()->depth) {
            node *tmp = b.grandfa();
            a.grandfa()->fa = tmp;
            tmp->depth++;
        }
        else{
            if(a.depth < b.depth) {
                a.grandfa()->fa = b.grandfa();
            }
            else {
                b.grandfa()->fa = a.grandfa();
            }
        }
    }
}

int main() {
    node nodes[1001];
    // std::vector<node> nodes(1001);
    int cities, roads, t1, t2, count;
    while(std::scanf("%d", &cities), cities) 
    {
        count = 0;
        for(int i = 1; i <= cities; i++) nodes[i].init();
        for(std::scanf("%d", &roads); roads > 0; roads--) 
        {
            scanf("%d %d", &t1, &t2);
            unite(nodes[t1], nodes[t2]);
        }
        count = -1;
        for(int i = 1; i <= cities; i++)
        {
            if(nodes[i].fa == &nodes[i]) count++;
        }
        std::printf("%d\n", count);
    }
    return 0;
}