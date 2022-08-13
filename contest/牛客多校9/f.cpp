#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n,m,p,x,a,b,c;

int f(int x){
    // return (a*x*x+b*x+c)%p;
    return (((a*x%p)*x%p+b*x%p)%p+c)%p;
}

void sol(){
    cin>>n>>m>>p>>x>>a>>b>>c;
    vector<int> s(n+1),t(m+1);
    unordered_map<int,int> loc;
    for(int i=1;i<=n;i++){
        s[i]=f(x);
        x=s[i];
        if(loc.count(s[i])) continue;
        loc[s[i]]=i;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        t[i]=f(x);
        x=t[i];
        if(loc.count(t[i])){
            int res=min({n-loc[t[i]]+1,m-i+1});
            ans=max(ans,res);
            // break;
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
