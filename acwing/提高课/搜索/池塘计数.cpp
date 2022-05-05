#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>


const int maxn=1100;
char mp[maxn][maxn];
bool st[maxn][maxn];
int n,m;
int ans;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


void bfs(int x,int y){
    queue<pii> q;
    q.push({x,y});

    while(q.size()){
        int x=q.front().first,y=q.front().second;
        mp[x][y]='.';
        q.pop();

        for(int i=0;i<8;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(mp[xx][yy]=='W') q.push({xx,yy}),mp[xx][yy]='.';
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='W') bfs(i,j),ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}