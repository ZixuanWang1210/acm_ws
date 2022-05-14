#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    s=' '+s;
    int n=s.length()-1;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1]+(s[i]=='1');
    }
    int cnt=v[n];
    int ans=0x3f3f3f3f;

    for(int i=cnt;i<=n;i++){
        ans=min(ans,cnt-v[i]+v[i-cnt]);
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
