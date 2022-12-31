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
    int n,m; cin>>n>>m;
    vector<string> v;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        v.push_back(s);
    }
    auto get=[&](string s1,string s2){
        int res=0;
        for(int i=0;i<m;i++){
            res+=abs(s1[i]-s2[i]);
        }
        return res;
    };
    int ans=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=min(ans,get(v[i],v[j]));
        }
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
