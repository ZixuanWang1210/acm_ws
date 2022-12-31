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
    int n,k; cin>>n>>k;
    vector<int> vv(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>vv[i];
        mp[vv[i]]++;
    }
    vector<int> v;
    for(auto x:mp){
        if(x.second<k) continue;
        else v.push_back(x.first);
    }
    int l=-1,r=-1;
    int res=0;
    int re=-2;
    for(int i=0;i<v.size();i++){
        if(re+1!=v[i]) r=l=i,r++;
        else r++;
        res=max(res,r-l+1);
        re=v[i];
    }
    cout<<res<<endl;
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
