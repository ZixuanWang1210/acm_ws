#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1),a(n+1);
    vector<pii> res;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        res.push_back({v[i]+i,i});
    }

    sort(_all(res),greater<pii>());

    for(int i=0;i<k;i++) a[res[i].second]=1;

    int cnt=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) ans+=v[i]+cnt; 
        else cnt++;
    }

    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
