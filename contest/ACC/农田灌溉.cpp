#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(2*n);
    int _max=0;
    for(int i=1;i<=k;i++){
        cin>>v[i];
        if(i==1) continue;
        int dis=v[i]-v[i-1];
        // cout<<dis<<endl;;
        _max=max(_max,dis);
    }
    // cout<<_max<<endl;
    _max/=2;
    _max++;
    _max=max(_max,max(v[1],n-v[k]+1));
    // _max=max(_max,n-v[n]);
    cout<<_max<<endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
