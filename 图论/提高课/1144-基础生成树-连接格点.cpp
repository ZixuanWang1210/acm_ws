#include<bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int m,n;
struct oppo{
    int x,y;
    bool operator!=(const oppo a)
    {
        if(a.x==x&&a.y==y)
            return 0;
        return 1;
    }
}fa[1005][1005];
int ans;
oppo find(int x,int y)
{
    if(fa[x][y].x==x&&fa[x][y].y==y)
        return fa[x][y];
    return fa[x][y]=find(fa[x][y].x,fa[x][y].y);
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            fa[i][j].x=i;
            fa[i][j].y=j;
        }
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        oppo k=find(a,b);
        oppo f=find(c,d);
        if(k!=f)
        {
            fa[k.x][k.y].x=f.x;
            fa[k.x][k.y].y=f.y;
        }
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<=n;j++)
        {
            oppo k=find(i,j);
            oppo f=find(i+1,j);
            if(k!=f)
            {
                fa[k.x][k.y].x=f.x;
                fa[k.x][k.y].y=f.y;
                ans+=1;
            }
        }
    for(int i=1;i<=m;i++)
        for(int j=1;j<n;j++)
        {
            oppo k=find(i,j);
            oppo f=find(i,j+1);
            if(k!=f)
            {
                fa[k.x][k.y].x=f.x;
                fa[k.x][k.y].y=f.y;
                ans+=2;
            }
        }
    cout<<ans<<endl;
    return 0;
}