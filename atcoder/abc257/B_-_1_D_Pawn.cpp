#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n,k,q; cin>>n>>k>>q;
    vector<int> v(k+2);
    for(int i=1;i<=k;i++){
        cin>>v[i];
    }
    v[k+1]=inf;
    while(q--){
        int x; cin>>x;
        if(v[x]<n&&v[x+1]!=v[x]+1){
            v[x]++;
        }
    }
    for(int i=1;i<=k;i++){
        cout<<v[i]<<' ';
    }

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
