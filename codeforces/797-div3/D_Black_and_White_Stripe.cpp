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
    int n; cin>>n;
    int k; cin>>k;
    string s; cin>>s;
    s=' '+s;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='B') v[i]++;
    }
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    int ans=inf;
    for(int i=1,j=k;j<=n;j++,i++){
        ans=min(ans,k-v[j]+v[i-1]);
    }
    cout<<ans<<endl;
    

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
