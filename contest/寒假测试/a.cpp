#include <bits/stdc++.h>
#define pii pair<int,int>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6+10;
int mp[maxn][maxn];
int st[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,x,y;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    queue<pii> q;

    q.push({1, 1});
    st[1][1] = 0;
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            int x = q.front().first, y = q.front().second;
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
                st[xx][yy] = min(st[xx][yy],st[x][y] + mp[x][y]);
                q.push({xx, yy});
            }
        }
        q.pop();
    }

    return 0;
}
