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

const int maxn=1e4+10;
double f[maxn][maxn];
int w[maxn];
int n;

double dp(int x,int y){
    if(f[x][y]) return f[x][y];
    if(x==0&&y==0) return 1;
    else if(x==0) return 0;
    double &v=f[x][y];
    v=1.0;

    for(int i=1;i<=w[x];i++){
        if(y-i>0) v+=1/w[x]*dp(x-1,y-i);
    }
    return v;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    // for(int i=1;i<=w[1];i++){
    //     f[0][i]=1;
    // }
    // int sum; cin>>sum;
    // cout<<dp(n,sum)<<endl;
    cout<<dp(1,3)<<endl;


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
