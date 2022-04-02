#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,pair<int,int>>
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    vector<pii> s;
    int sum=1;
    int idx=0;
    int cntfu=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==0){
            idx=i-1;
            s.push_back({sum,{idx,i}});
            sum=1;
        }
        if(v[i]<0) cntfu++;
    }

    if(cntfu%2==0){
        
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
