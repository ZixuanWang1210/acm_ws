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
    int n,k; cin>>n>>k;
    vector<int> v(n+1);
    vector<int> b[k];
    for(int i=1;i<=n;i++){
        cin>>v[i];
        b[v[i]%k].push_back(v[i]);
    }

    int ans=0;
    vector<int> res;
    for(int i=0;i<k;i++){
        sort(b[i].begin(),b[i].end(),greater<int>());
        int nn=b[i].size();
        if(nn&1) res.push_back(b[i][nn-1]);
        for(int j=1;j<nn;j+=2){
            ans+=(b[i][j]+b[i][j-1])/k;
        }
    }

    int nnn=res.size();
    for(int i=1;i<nnn;i+=2){
         ans+=(v[i]+v[i-1])/k;
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
