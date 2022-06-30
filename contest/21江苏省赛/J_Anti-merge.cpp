#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=510;
int mp[maxn][maxn];
int n,m;
vector<pii> ans;
bool st[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

vector<pii> num1,num0;

void dfs(int x,int y,int col){
    st[x][y]=1;
    if(col==0) num0.push_back({x,y});
    else num1.push_back({x,y});

    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||st[xx][yy]) continue;
        if(mp[xx][yy]!=mp[x][y]) continue;
        dfs(xx,yy,col^1);

    }
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!st[i][j]){
                num0.clear();
                num1.clear();

                dfs(i,j,0);
                int cnt0=num0.size(),cnt1=num1.size();

                if(cnt0>=cnt1){
                    for(auto x:num1){
                        ans.push_back(x);
                    }
                }
                else{
                    for(auto x:num0){
                        ans.push_back(x);
                    }
                }
            }

        }
    }
    if(ans.size()) cout<<1<<' ';
    else{
        cout<<"0 0"<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<' '<<1<<endl;
    }


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
