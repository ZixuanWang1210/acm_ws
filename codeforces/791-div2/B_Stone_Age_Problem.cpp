#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int lazy=0;
    map<int,int> mp;
    while(q--){
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            if(mp[x]==1||lazy==0) sum-=v[x];
            else sum-=lazy,mp[x]=1;
            sum+=y;
            v[x]=y;
        }
        else{
            int x; cin>>x;
            sum=x*n;
            mp.clear();
            lazy=x;
        }
        cout<<sum<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
