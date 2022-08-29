#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=200;
int dis[maxn][maxn];
bool st[maxn][maxn]={0};

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];
        }
    }

    vector<pii> res;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool ok=true;
            for(int k=1;k<=n;k++){
                if(k==i||k==j) {continue;}
                if(dis[i][k]+dis[k][j]==dis[i][j]) ok=false;
            }
            if(ok) res.push_back({i,j});
        }
    }
    cout<<res.size()<<endl;
    for(auto x:res){
        cout<<x.first<<' '<<x.second<<endl;
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         if(i==j) continue;
    //         if(!st[i][j]) cout<<i<<" "<<j<<endl;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         if(!st[i][j]) res.push_back({i,j});
    //     }
    // }
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
