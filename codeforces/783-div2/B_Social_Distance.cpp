#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++) cin>>v[i],sum+=v[i];
    int _min=*min_element(v.begin()+1,v.begin()+1+n);
    int _max=*max_element(v.begin()+1,v.begin()+1+n);
    cout<<(n+sum-_min+_max<=m?"YES":"NO")<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
