#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int x; cin>>x;
    // int sum=0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.end());

    long long ans=0,sum=0;
    for(int i=1;i<=n;i++){
        sum+=v[i];
        if(x-sum>=0) ans+=((x-sum)/i+1);
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
