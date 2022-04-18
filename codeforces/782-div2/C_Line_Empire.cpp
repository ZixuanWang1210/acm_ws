#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,a,b; 
    cin>>n>>a>>b; 
    vector<int> v(n+1);
    int res=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        ans+=b*(v[i]-res);
        if((n-i)*b>a){
            ans+=a*(v[i]-res);
            res=v[i];
        }
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
