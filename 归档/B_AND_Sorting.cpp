#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),a(n+1);

    for(int i=1;i<=n;i++) cin>>v[i],a[i]=v[i];

    sort(a.begin()+1,a.begin()+1+n);

    int ans=0;
    vector<int> res;

    for(int i=1;i<=n;i++){
        if(a[i]!=v[i]) res.push_back(v[i]);
    }

    for(int i=1;i<res.size();i++){
        res[i]&=res[i-1];
    }

    cout<<res[res.size()-1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
