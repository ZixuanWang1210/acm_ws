#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int x; cin>>x;
    vector<int> v(n+1),vv(n+1);
    v[0]=1;
    int tt=0;
    int anst=0;
    bool hav0=false;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        // if(v[i]!=0) tt++;
        // else anst+=tt*(tt-1)/2+tt,tt=0,hav0=true;
        v[i]%=mod;
        vv[i]=v[i];
        v[i]=v[i-1]*v[i];
        v[i]%=mod;
        // cout<<v[i]<<" ";
        // cout<<v[i]<<endl;
    }
    if(x==0){
        // cout<<anst<<endl;
        int last=0;
        for(int i=1;i<=n;i++){
            if(vv[i]==0){
                anst+=(i-last)*(n-i+1);
                last=i;
            }
        }
        cout<<anst<<endl;
        return;
    }
    map<int,int> mp;
    mp[x]=1;
    int ans=0;
    // for(int i=1;i<=n;i++){
    //     // if(v[i]==6) ans++;
    //     if(v[i])
    //     ans+=mp[v[i]/x];
    //     mp[v[i]]++;

    // }

    int now=1;
    for(int i=1;i<=n;i++){
        if(vv[i]==0){
            mp.clear();
            mp[x]=1;
            now=1;
        }
        else{
            now=now*vv[i]%mod;
            ans+=mp[now];
            mp[now*x%mod]++;
        }
    }

    cout<<ans<<endl;

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
