#define ctype int

const int maxn = 1000;
const ctype no_way = 0x3f3f3f3f;    // no way through

bool vis[maxn], pre[maxn];

void djikstra(ctype map[][maxn], ctype dis[maxn], const int &begin, const int &nodes)
{
    for(int i = 1; i <= nodes; i++)
    {   // initialization
        vis[i] = false;
        dis[i] = no_way;
        pre[i] = -1;
    }
    
    int cur;
    ctype Min = no_way;
    dis[begin] = 0;
    for(int j = 1; j <= nodes; j++)
    {
        cur = -1;
        Min = no_way;
        for(int i = 1; i <= nodes; i++) // finds the currently shortest path
            if(!vis[i] && dis[i] < Min)
            {
                Min = dis[i];
                cur = i;
            }
        if(cur == -1) break;
        
        vis[cur] = true;    // visit this node

        for(int i = 1; i <= nodes; i++)
            if(!vis[i] && dis[i] > dis[cur] + map[cur][i])
            {
                dis[i] = dis[cur] + map[cur][i];
                pre[i] = cur;
            }
    }
    return;
}