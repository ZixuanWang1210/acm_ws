#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

map<string,vector<int>> mp;

int get(int n){
    return n*(n-1)/2;
}

int ans;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        mp[s].push_back(i);
    }

    for(auto x:mp){
        for(int i=0;i<x.second.size();i++){
            
        }
    }    
    cout<<ans<<endl;

    return 0;
}
