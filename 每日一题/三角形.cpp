#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
#define int long long
// typedef unsigned long long ull;

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<pii> v(2*n);

    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int _max=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j||i==k||j==k) continue;
                if(v[i].first==v[j].first&&v[i].second==v[k].second){
                    _max=max(_max,abs(v[i].second-v[j].second)*abs(v[i].first-v[k].first));
                }
            }
        }
    }
    cout<<_max<<endl;
    

    return 0;
}
