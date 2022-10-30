#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353 
#define ll long long
using namespace std;

const int maxn = 5e5 + 10, P = 998244353 ;
ll fact[maxn], infact[maxn];

ll qmi(int a,int k,int p=mod){
    int res=1;
    while(k){
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 5e5; i++) {
        fact[i] = (ll)fact[i - 1] * i % P;
        infact[i] = (ll)infact[i - 1] * qmi(i, P - 2, P) % P;
    }
}

ll get(int a,int b){
    return (ll)fact[a] * infact[b] % P * infact[a - b] % P;
}

void sol(){
    init();
    int n,m; cin>>n>>m;
    vector<int> v(n+1);
    int mx=0;
    set<int> st;
    map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>v[i],mx=max(mx,v[i]),st.insert(v[i]),mp[v[i]]++;
    for(int i=1;i<=m;i++){
        if(i<mx) cout<<0<<endl;
        else{
            ll res=1;
            // for(int j=1;j<=n;j++){
            //     if(v[j]==0) continue;
            //     res=res*get(i,v[j])%mod;
            // }
            for(auto x:st){
                res=(res*qmi(get(i,x),mp[x]))%mod;
            }
            cout<<res<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    while(_--){
        sol();
    }

    return 0;
}
