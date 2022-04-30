#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,x; cin>>n>>x;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++) cin>>v[i];
    v[n+1]=0;

    sort(v.begin()+1,v.begin()+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        // cout<<v[i]<<' ';
        if(v[i]+v[i+1]>=x) cnt++;
    }
    // if(cnt!=n)  cnt++;
    cout<<cnt<<endl;
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
