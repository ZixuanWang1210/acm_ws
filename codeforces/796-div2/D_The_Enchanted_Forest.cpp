#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    int ans=0;
    for(int i=min(n,k);i<=n;i++){
        int idx=max(0ll,i-k-1);
        ans=max(ans,s[i]-s[idx]);
    }
    if(k>n)
    cout<<s[n]+n*k-n*(n+1)/2<<endl;
    else{
        ans+=k*(k-1)/2;
        cout<<ans<<endl;
    }


    // if(n>k){
    //     cout<<s[n]+n*k-n*(n+1)/2<<endl;
    //     return;
    // }
    // cout<<ans<<endl;
    // ans+=n*(n-1)/2;

    // cout<<ans<<endl;

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
