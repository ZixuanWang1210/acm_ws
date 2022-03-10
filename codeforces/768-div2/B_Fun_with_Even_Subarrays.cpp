#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    int ans=0;
    for(int i=n-1;i>=1;i--){
        if(v[i]==v[n]) continue;
        else{
            ans++;
            i-=(n-i);
            i++;
        }
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
