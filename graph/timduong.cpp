#include<iostream>

using namespace std;

int n,m,s1,s2,t1,t2;
char a[505][505];
int ok=0;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void ql(int i,int j,int k_pre,int cnt)
{
    if (cnt>3) return ;
    if (i==t1 && j==t2)
    {
        ok=1;
        return ;
    }
    if (ok) return;
    a[i][j]='*';
    for (int k=0;k<4;k++)
    {
        int i1=i+dx[k],j1=j+dy[k];
        if (i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]!='*')
        {
            if (k_pre==k)
            {
                ql(i1,j1,k,cnt);
            }
            else ql(i1,j1,k,cnt+1);
        }
    }
    a[i][j]='.';
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S')
            {
                s1=i;s2=j;
            }
            if (a[i][j]=='T')
            {
                t1=i;t2=j;
            }
        }
    }
    ql(s1,s2,-1,0);
    if (ok) cout<<"YES";
    else cout<<"NO";
    return 0;
}