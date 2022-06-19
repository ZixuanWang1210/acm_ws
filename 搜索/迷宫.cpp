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
char mp[maxn][maxn];
bool st[maxn][maxn];
int n;
int stx,sty,edx,edy;

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool dfs(int x,int y){
    if(x==edx&&y==edy) return true;
    st[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=n) continue;
        if(mp[xx][yy]=='#') continue;
        if(st[xx][yy]) continue;
        if(dfs(xx,yy)) return true;
    }
    return false;
}

void sol(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    cin>>stx>>sty>>edx>>edy;
    if(mp[stx][sty]=='#'||mp[edx][edy]=='#'){
        cout<<"NO"<<endl;
        return ;
    }
    memset(st,0,sizeof st);
    if(dfs(stx,sty)){
        cout<<"YES"<<endl;
        return ;
    }
    else cout<<"NO"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
