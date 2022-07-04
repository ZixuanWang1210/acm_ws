#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,pair<int,int>>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }    
    priority_queue<pii> vec;
    int l=1;
    for(int i=1;i<=n;i++){
        if(v[i]<=v[i-1]){
            int r=i-1;
            vec.push({r-l+1,{l,r}});
            l=i;
        }
    }
    int r=n;
    vec.push({r-l+1,{l,r}});

    int ans=0;
    if(vec.size()>2){
        int t=vec.top().first;
        ans+=t;
        vec.pop();
        ans+=vec.top().first;
    }
    else ans=vec.top().first;
    cout<<ans<<endl;
    // for(auto x:vec){
    //     cout<<x.second.first<<' '<<x.second.second<<endl;
    // }

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
