#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long 
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    int res=1e18;
    for(int i=2;i<=n-1;i++){
        int det=abs(v[i-1]-v[i+1]);
        int t=min(v[i-1],v[i+1])+(det+1)/2;
        res=min(res,t);
    }

    for(int i=1;i<=n-1;i++){
        if(v[i]>=v[i+1]*2) res=min(res,(v[i]+1)/2);
        else if(v[i+1]>=v[i]*2) res=min(res,(v[i+1]+1)/2);
        else res=min(res,(v[i]+v[i+1]+2)/3);
    }

    sort(v.begin()+1,v.begin()+1+n);
    res=min(res,((v[1]+1)/2+(v[2]+1)/2));

    cout<<res<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
