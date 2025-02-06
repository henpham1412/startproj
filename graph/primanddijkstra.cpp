#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
bool taken[10001];
vector<pair<int,int>> adj[100001];


void nhap()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}

void prim(int s)
{
    taken[s]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (auto it:adj[s])
    {
        if (!taken[it.first])
        {
            pq.push({it.second,it.first});
        }
    }
    long long d=0,cnt=0;
    while (!pq.empty())
    {
        auto e=pq.top();pq.pop();
        int u=e.second,w=e.first;
        if (!taken[u])
        {
            ++cnt;
            d+=w;
            taken[u]=true;
            for (auto it:adj[u])
            {
                if (!taken[it.first])
                {
                    pq.push({it.second,it.first});
                }
            }
        }
    }
    if (cnt==n-1) cout<<d<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}

void dijkstra(int s)
{
    vector<int> d(n+1,1e9);
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto e=pq.top();pq.pop();
        int u=e.second,kc=e.first;
        if (kc>d[u]) continue;
        for (auto it:adj[u])
        {
            int v=it.first,w=it.second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<i<<" "<<d[i]<<endl;
    }
}

int main()
{
    nhap();
    dijkstra(1);
    return 0;
}