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
    int n,a,b,c,t;
    cin>>n>>a>>b>>c>>t;
    vector<int> v(n+1);
    int res=0,s=0;
    res=n*a;
    if(b>=c){
        cout<<res<<endl;
        return;
    }

    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1;i<=n;i++){
        s=s+(t-v[i]);
    }
    
    cout<<res+s*(c-b)<<endl;
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
