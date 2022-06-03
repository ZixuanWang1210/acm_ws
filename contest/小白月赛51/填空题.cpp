#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int mn=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(v[i]==0) v[i]=v[i-1]+1;
        if(v[i]<=v[i-1]){
            cout<<-1<<endl;
            return;
        }
        s[i]=s[i-1]+v[i];
    }
    cout<<s[n]<<endl;

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
