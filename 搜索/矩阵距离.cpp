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

const int maxn=1100;
int n,m;
int mp[maxn][maxn];
int dis[maxn][maxn];
queue<pii> q;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};


void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++){
            mp[i][j+1]=s[j]-'0';
            if(mp[i][j+1]){
                q.push({i,j+1});
            }
        }
    }

    while(q.size()){
        int x=q.front().first,y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]==1) continue;
            if(dis[xx][yy]) continue;
            dis[xx][yy]=dis[x][y]+1;
            q.push({xx,yy});
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]) cout<<0<<' ';
            else cout<<dis[i][j]<<' ';
        }
        cout<<endl;
    }
    return;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
