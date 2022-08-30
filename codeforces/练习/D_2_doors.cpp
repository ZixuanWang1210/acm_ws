#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n,q; cin>>n>>q;
    vector<int> opt(n+1,(1<<30)-1);
    vector<int> ans(n+1,0);
    vector<bool> st(n+1,0);
    map<int,vector<pii>> mp;
    while(q--){
        int i,j,k; cin>>i>>j>>k;
        if(i==j) ans[i]=k,st[i]=true;
        opt[i]&=k;
        opt[j]&=k;
        mp[i].push_back({j,k});
        mp[j].push_back({i,k});
    }
    for(int i=1;i<=n;i++){
        for(auto x:mp[i]){
            int t=0;
            if(st[x.first]) t=ans[x.first]^x.second;
            else t=x.second^opt[x.first];
            ans[i]|=t;
        }
        st[i]=true;
        cout<<ans[i]<<' ';
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
