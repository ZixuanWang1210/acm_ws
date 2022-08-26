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

const int maxn=1e7;
int f[maxn];

void sol(){
    f[1]=f[2]=1;
    int idx=3;
    while(1){
        f[idx]=f[idx-1]+f[idx-2];
        if(f[idx]>5e18) break;
        idx++;
    }
    // cout<<f[idx]<<' '<<idx<<endl;
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        int pos=lower_bound(f+1,f+idx+1,x)-f;
        cout<<(abs(f[pos]-x)<abs(f[pos-1]-x)?pos:pos-1)<<endl;
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
