#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=10;
int g[maxn][maxn]={
    {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};
int dx[]={0,1,1,-1,-1,2,2,-2,-2};
int dy[]={0,2,-2,2,-2,1,-1,1,-1};
int mp[maxn][maxn];
int n,m,t;
int x,y;
bool ok;

int check(){
    int cnt=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(g[i][j]!=mp[i][j]) cnt++;
        }
    }
    return cnt;
}

void dfs(int dep,int x,int y,int mxdep){
    if(dep==mxdep){
        if(!check()) ok=1;
        return;
    }
    for(int i=1;i<=8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>5||yy<1||yy>5) continue;
        swap(mp[xx][yy],mp[x][y]);
        if(check()+dep<=mxdep){
            dfs(dep+1,xx,yy,mxdep);
        }
        swap(mp[xx][yy],mp[x][y]);
    }
}

void sol(){
    ok=false;
    for(int i=1;i<=5;i++){
        string s; cin>>s;
        for(int j=0;j<5;j++){
            if(s[j]=='*') mp[i][j+1]=2,x=i,y=j+1;
            else mp[i][j+1]=s[j]-'0';
        }
    }
    if(!check()) cout<<0<<endl;

    for(int i=1;i<=15;i++){
        dfs(0,x,y,i);
        if(ok){
            cout<<i<<endl;
            break;
        }
    }
    if(!ok){
        cout<<-1<<endl;
    }
    return;

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
