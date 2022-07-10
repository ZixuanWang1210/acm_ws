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
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    map<char,int> mp;
    for(auto x:s1){
        mp[x]++;
    }
    int res1=0,res2=0;
    for(auto x:mp){
        if(x.second&1) res1++;
    }
    mp.clear();

    for(auto x:s2){
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second&1) res2++;
    }

    cout<<res1<<endl;
    if(res1<res2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
