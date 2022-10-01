#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    if(n==1){
        int x; cin>>x;
        cout<<0<<endl;
        return;
    }
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<pii> res;
    if((v[n]&1)!=(v[1]&1)){
        if(v[1]%2==0){
            res.push_back({1,n});
            v[n]=v[1];
            for(int i=2;i<=n-1;i++){
                if(v[i]&1){
                    res.push_back({1,i});
                }
                else{
                    res.push_back({i,n});
                }
            }
            cout<<res.size()<<endl;
            for(auto x:res) {
                cout<<x.first<<' '<<x.second<<endl;
            }
        }
        else{
            res.push_back({1,n});
            v[n]=v[1];
            for(int i=2;i<=n-1;i++){
                if(v[i]%2==0){
                    res.push_back({1,i});
                }
                else{
                    res.push_back({i,n});
                }
            }
            cout<<res.size()<<endl;
            for(auto x:res) {
                cout<<x.first<<' '<<x.second<<endl;
            }
        }
    }
    else{
        if(v[1]&1){
            res.push_back({1,n});
            for(int i=2;i<=n-1;i++){
                if(v[i]%2==0){
                    res.push_back({1,i});
                }
                else{
                    res.push_back({i,n});
                }
            }
            cout<<res.size()<<endl;
            for(auto x:res) {
                cout<<x.first<<' '<<x.second<<endl;
            }
        }
        else{
            res.push_back({1,n});
            for(int i=2;i<=n-1;i++){
                if(v[i]&1){
                    res.push_back({1,i});
                }
                else{
                    res.push_back({i,n});
                }
            }
            cout<<res.size()<<endl;
            for(auto x:res) {
                cout<<x.first<<' '<<x.second<<endl;
            }
        }
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
