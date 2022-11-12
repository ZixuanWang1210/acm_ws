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
    vector<int> v(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<int> vec;
    map<int,int> mp;
    int cnt=0;
    bool ok=false;
    while(k--){
        int x,y; cin>>x>>y;
        mp[x]=y;
        if(x==0) mp[x]=y,ok=true;
        if(y==0) vec.push_back(x+1);
    }
    vec.push_back(-1);
    sort(_all(vec));
    for(int i=1;i<=n;i++){
        b[i]=*prev(upper_bound(_all(vec),v[i]));
    }
    int idx=0;
    for(int i=1;i<=n;i++){
        if(b[i]==-1){
            if(mp[idx]==0)
        }
    }
    cout<<endl;


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
