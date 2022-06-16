#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;
int dx[]={-1,-1,1,1},dy[]={-1,1,1,-1};
int ix[]={-1,-1,0,0},iy[]={-1,0,0,-1};
char ch[]={'\\', '/', '\\', '/'};
const int maxn=600;
char mp[maxn][maxn];
int dis[maxn][maxn];
bool st[maxn][maxn];

void sol(){
    int r,c; cin>>r>>c;

    for(int i=0;i<r;i++) cin>>mp[i];

    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);

    deque<pii> dp;
    dis[0][0]=0;
    dp.push_back({0,0});
    while(dp.size()){
        int x=dp.front().first,y=dp.front().second;
        dp.pop_front();

        if(st[x][y]) continue;
        st[x][y]=true;

        int dist=dis[x][y];
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>r||yy<0||yy>c) continue;
            int ex=x+ix[i],ey=y+iy[i];
            int w=mp[ex][ey]!=ch[i];
            int d=dis[x][y]+w;
            if(d<=dis[xx][yy]){
                dis[xx][yy]=d;
                if(!w) dp.push_front({xx,yy});
                else dp.push_back({xx,yy});
            }
        }
    }

    if(dis[r][c]==inf) cout<<"NO SOLUTION"<<endl;
    else cout<<dis[r][c]<<endl;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
