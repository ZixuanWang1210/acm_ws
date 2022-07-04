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
const int maxn=2e5+10;
int a[maxn],b[maxn];
int sum[maxn]={0};

void sol(){
    int n,x; cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i]+b[i];
    }

    int res=2e18;
    for(int i=1;i<=min(n,x);i++){
        int now=sum[i];
        int tt=x-i;
        if(tt){
            now+=tt*b[i];
        }
        res=min(res,now);
    }
    cout<<res<<endl;

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
