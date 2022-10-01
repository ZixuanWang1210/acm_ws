#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n,c; cin>>n>>c;
    // vector<int> v;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    int res=0;
    for(auto x:mp){
        if(x.second>=c) res+=c;
        else res+=x.second;
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
