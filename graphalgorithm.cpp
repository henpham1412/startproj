#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int x,y,w;
};

int n,m,max_sz=1;
int sz[1000001],parent[1000001];
vector<edge> dscanh;

void init()
{
    for (int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int u)
{
    if (u==parent[u]) return u;
    else return parent[u]=find(parent[u]);
}

bool Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y) return false;
    else
    {
        if (sz[x]>sz[y])
        {
            parent[y]=x;
            sz[x]+=sz[y];
        }
        else
        {
            parent[x]=y;
            sz[y]+=sz[x];
        }
        max_sz=max({max_sz,sz[x],sz[y]});
        return true;
    }
}

// void nhap()
// {
//     cin>>n>>m;
//     for (int i=0;i<m;i++)
//     {
//         int x,y,w;cin>>x>>y>>w;
//         edge e{x,y,w};
//         dscanh.push_back(e);
//     }
// }

// void Kruskal()
// {
//     sort(dscanh.begin(),dscanh.end(),[](const edge &a,const edge &b)->bool{
//         return a.w<b.w;
//     });
//     int d=0;
//     vector<edge> MST;
//     for (int i=0;i<m;i++)
//     {
//        if (MST.size()==n-1) break;
//        edge e=dscanh[i];
//        if (Union(e.x,e.y))
//        {
//             d+=e.w;
//             MST.push_back(e);
//        } 
//     }
//     cout<<d<<endl;
//     for (auto e:MST)
//     {
//         cout<<e.x<<" "<<e.y<<" "<<e.w<<endl;
//     }
// }

int main()
{
    cin>>n>>m;
    init();
    int cnt=n;
    for (int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        if (Union(x,y))
        {
            --cnt;
        }
        cout<<cnt<<" "<<max_sz<<endl;
    }
    return 0;
}