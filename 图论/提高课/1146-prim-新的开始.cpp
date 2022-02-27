#include<bits/stdc++.h>
using namespace std;

const int maxn=310;
int g[maxn][maxn];
int dis[maxn];
bool st[maxn];
int n;

int prim(){
    memset(dis,0x3f,sizeof dis);
    dis[0]=0;

    int res=0;
    for(int i=0;i<n+1;i++){
        int t=-1;
        for(int j=0;j<=n;j++)
            if(!st[j]&&(t==-1||dis[t]>dis[j]))
                t=j;
            
        st[t]=true;
        res+=dis[t];

        for(int j=0;j<=n;j++){
            dis[j]=min(dis[j],g[t][j]);
        }
    }
    return res;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        g[i][0]=g[0][i]=t;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }

    cout<<prim()<<endl;

    return 0;
}