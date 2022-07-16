#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int x; cin>>x;
    vector<int> v(2*n+1);
    for(int i=1;i<=2*n;i++) cin>>v[i];
    sort(all(v));
    for(int i=1,j=n+1;i<=n;i++,j++){
        if(v[j]-v[i]<x){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;

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
