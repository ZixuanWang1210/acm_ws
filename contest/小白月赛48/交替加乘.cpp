#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;
const int mod=1e9+7;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),ans(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin()+1,v.end());

    for(int i=1;i<=n;i++){
        if(i%2) ans[i]=v[n/2+(i+1)/2];
        else ans[i]=v[n/2-(i/2-1)];
    }

    int res=ans[1];
    for(int i=2;i<=n;i++){
        if(i%2) res=res*ans[i]%mod;
        else res=(res+ans[i])%mod;
    }
    cout<<res<<endl;
    
    

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
