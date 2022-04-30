#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int unsigned long long

using namespace std;

void sol(){
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    
    int ans=0;
    for(auto x:mp){
        if(x.second>=3){
            int tt=x.second;
            ans+=(tt*(tt-1)*(tt-2)/6);
        }
    }

    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b; 
        // if(v[a]==b){
        //     cout<<ans<<endl;
        //     continue;
        // }
        if(mp[v[a]]>=3){
            int tt=mp[v[a]];
            ans-=(tt*(tt-1)*(tt-2)/6);
        }
        mp[v[a]]--;
        if(mp[v[a]]>=3){
            int tt=mp[v[a]];
            ans+=(tt*(tt-1)*(tt-2)/6);
        }
        v[a]=b;


        if(mp[b]>=3){
            int tt=mp[b];
            ans-=(tt*(tt-1)*(tt-2)/6);
        }
        mp[b]++;
        if(mp[b]>=3){
            int tt=mp[b];
            ans+=(tt*(tt-1)*(tt-2)/6);
        }
        cout<<ans<<endl;
    }


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
