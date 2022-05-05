#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1),sum(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin()+1,v.begin()+1+n);
    
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+v[i];
    }

    int ans=0x3f3f3f3f;
    for(int i=0;i<=n-1;i++){
       int temp=v[1]+ceil(-(k-sum[n-i]+sum[1])/(i+1.0));
       if(temp<0) temp=0;
       ans=min(ans,temp+i);
    }

    cout<<ans<<endl;
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
