#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define fi first
#define se second

int n,t,cnt;
const int maxn=200;
pii match[maxn][maxn];
bool st[maxn][maxn];
int g[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool find(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(!g[xx][yy]&&xx&&xx<=n&&yy&&yy<=n&&!st[xx][yy]){
            st[xx][yy]=true;
            pii t=match[xx][yy];
            if(t.fi==-1||find(t.fi,t.se)){
                match[xx][yy]={x,y};
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>t;
    for(int i=1;i<=t;i++){
        int x,y; cin>>x>>y;
        g[x][y]=1;
    }
    memset(match,-1,sizeof match);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            memset(st,0,sizeof st);
            if((i+j)%2&&!g[i][j]){
                if(find(i,j)) cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}