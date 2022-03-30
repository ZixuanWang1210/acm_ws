#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

unordered_map<string,vector<int>> mp;

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
        if(x.second.size()==1) continue;
        for(int i=0;i<x.second.size()-1;i++){
            int fi=x.second[i];
            int cnt=lower_bound(x.second.begin(),x.second.end(),fi+k+1)-x.second.begin()-i;
            cnt--;
            ans+=cnt;
        }
    }    
    cout<<ans<<endl;

    return 0;
}
