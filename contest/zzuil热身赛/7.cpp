#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

#define pii pair<int,int>
#define int long long 
using namespace std;

const int maxn=2e5+10;

void sol(){
    int n; cin>>n;  
    int cnt=0;
    vector<pii> v;
    for(int i=1;i<=n;i++){
        int c,h; cin>>c>>h;
        v.push_back({-h,c});
    }
    sort(v.begin(),v.end());
    int len=v.size();
    for(int i=1;i<len;i++){
        if(v[i].second==3) cnt++;
        else if(v[i].second+v[i-1].second==3) cnt++;
    }
    cout<<cnt<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
