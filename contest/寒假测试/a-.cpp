#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int,pair<int,int>>
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1100;
int mp[maxn][maxn];
int dis[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,gx,gy;
bool st[maxn][maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>gx>>gy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,{1,1}});
    memset(dis,0x3f,sizeof dis);
    dis[1][1]=0;

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int x=t.second.first,y=t.second.second;
        int dist=t.first;
        if(st[x][y]) continue;
        st[x][y]=true;
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            if(dis[xx][yy]>dist+mp[xx][yy]){
                dis[xx][yy]=dist+mp[xx][yy];
                pq.push({dis[xx][yy],{xx,yy}});
            }
            if(xx==gx&&yy==gy){
                cout<<dis[xx][yy]<<endl;
                return 0;
            }
        }
    }
    

    return 0;
}
