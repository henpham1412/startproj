#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int n,m,a[1001][1001];

void dijkstra(int i,int j)
{
    vector<vector<int>> d(n+1,vector<int>(m+1,1e9));
    d[i][j]=a[i][j];
    priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> pq;
    pq.push({d[i][j],{i,j}});
    while (!pq.empty())
    {
        auto e=pq.top();pq.pop();
        auto x=e.second;int kc=e.first;
        if (kc>d[x.first][x.second]) continue; // kc>d[u]
        for (int k=0;k<4;k++)
        {
            int i1=x.first+dx[k],j1=x.second+dy[k];
            if (i1>=1 && i1<=n && j1>=1 && j1<=m)
            {
                if (d[i1][j1]>d[x.first][x.second]+a[i1][j1]) // d[v]>d[u]+w
                {
                    d[i1][j1]=d[x.first][x.second]+a[i1][j1];
                    pq.push({d[i1][j1],{i1,j1}});
                }
            }
        }
    }
    cout<<d[n][m];
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    dijkstra(1,1);
    return 0;
}