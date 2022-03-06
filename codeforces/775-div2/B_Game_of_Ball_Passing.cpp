#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
#define int long long 
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);

    for(int i=1;i<n;i++){
        sum+=v[i];
    }
    // cout<<sum <<" "<<v[n]<<' ';
    if(sum+v[n]==0) cout<<0<<endl;
    else if(sum>=v[n]) cout<<1<<endl;
    else cout<<v[n]-sum<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
