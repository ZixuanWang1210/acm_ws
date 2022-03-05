#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=110;
int g[maxn][maxn];
bool st[maxn][maxn];
pii match[maxn][maxn];
int n,m,t,cnt;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool find(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!g[xx][yy]&&!st[xx][yy]){
            st[xx][yy]=1;
            auto t=match[xx][yy];
            if(t.first==-1||find(t.first,t.second)){
                match[xx][yy]={x,y};
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=t;i++){
        int x,y; cin>>x>>y;
        g[x][y]=1;
    }
    memset(match,-1,sizeof match);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]||(i+j)%2) continue;
            memset(st,0,sizeof st);
            if(find(i,j)) cnt++;
        }
    }

    cout<<n*m-t-cnt<<endl;
    return 0;
}
