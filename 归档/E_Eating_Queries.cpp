#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long

using namespace std;

void sol(){
    int n,q; cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(all(v),greater<int>());
    for(int i=1;i<=n;i++)
        v[i]+=v[i-1];
    
    while(q--){
        int x; cin>>x;
        if(x>v[n]) cout<<-1<<endl;
        else cout<<lower_bound(all(v),x)-v.begin()<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
