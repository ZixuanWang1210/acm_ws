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
map<int,int> mp;

void sol(){
    int n,x; cin>>n>>x;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i],mp[v[i]]++;

    for(auto xx:mp){
        int num=xx.first,cnt=xx.second;
        int zu=cnt/(num+1);
        if(zu) mp[num+1]+=zu,mp[num]-=zu*(num+1);
        xx.second%=(num+1);
    }

    for(auto xx:mp){
        if(xx.second&&(xx.first)%x!=0){ cout<<"No"<<endl;return;}
    }
    
    cout<<"Yes"<<endl;
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
