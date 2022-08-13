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

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1),suma(n+1),sumb(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=2;i<=n;i++){
        suma[i]=suma[i-1]+max(0ll,v[i-1]-v[i]);
    }
    for(int i=n-1;i>=1;i--){
        sumb[i]=sumb[i+1]+max(0ll,v[i+1]-v[i]);
    }

    while(m--){
        int l,r; cin>>l>>r;
        if(l<r) cout<<suma[r]-suma[l]<<endl;
        else cout<<sumb[r]-sumb[l]<<endl;
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
