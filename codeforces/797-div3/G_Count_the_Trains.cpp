#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1);
    int mx=inf;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]<mx){
            mx=min(mx,v[i]);
            mp[i]=mx;
        }
    }

    while(m--){
        int x,y; cin>>x>>y;
        y=v[x]-y;
        auto idx=prev(mp.lower_bound(x));
        int id=idx->first;
        
        if(id==x){
            mp[id]=min(mp[id],y);
        }
        else{
            if(mp[id]>y){
                mp[x]=y;
            }
        }
        cout<<mp.size()<<' ';
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
