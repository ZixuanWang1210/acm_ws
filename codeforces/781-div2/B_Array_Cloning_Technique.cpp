#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    map<int,int> mp;
    int _max=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mp[v[i]]++;
        _max=max(_max,mp[v[i]]);
    }
    int res=0,cnt=n-_max;
    if(cnt==0) cout<<0<<endl;
    else{
        for(;_max<n;_max<<=1) res++;
        res+=cnt;
        cout<<res<<endl;
    }


}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
