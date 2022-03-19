#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<pair<int,int>,pair<int,int>>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int maxn=3000;
int mp[maxn][maxn];
bool st[maxn][maxn];
int sx,sy;
int n,m;
int costx,costy;
int cnt=1;

void bfs(){
    queue<pii> q;
    q.push({{sx,sy},{0,0}});
    st[sx][sy]=1;

    while(q.size()){
        int x=q.front().first.first,y=q.front().first.second;
        int ncostx=q.front().second.first,ncosty=q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            int ncx=ncostx,ncy=ncosty;
            if(i==0) ncx=ncostx+1;
            if(i==1) ncy=ncosty+1;
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]==-1||ncx>costx||ncy>costy||st[xx][yy]) continue;
            cnt++;
            st[xx][yy]=true;
            q.push({{xx,yy},{ncx,ncy}});
        }

    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>sx>>sy;
    cin>>costy>>costx;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t; cin>>t;
            if(t=='*') mp[i][j]=-1;
        }
    }
    bfs();
    cout<<cnt;

    return 0;
}
