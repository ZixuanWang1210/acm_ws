#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n);
    vector<int> b[k];
    for(int i=0;i<n;i++){
        cin>>v[i];
        b[i%k].push_back(v[i]);
    }
    for(int i=0;i<k;i++){
        sort(_all(b[i]));
        for(int j=0;j<b[i].size();j++){
            v[j*k+i]=b[i][j];
        }
    }

    if(is_sorted(_all(v))) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

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
