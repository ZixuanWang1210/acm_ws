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
vector<pii> v3,v4;
void sol(){
    v3.clear(),v4.clear();
    int n,k; cin>>n>>k;
    vector<int> v,v1;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        int cnt=1;
        if(x%k){
            if(v3.size()&&v3.back().first==x) v3.back().second+=cnt;
            else v3.push_back({x,cnt});
        }
        else{
            while(x%k==0){
                x/=k;
                cnt=cnt*k;
            }
            if(v3.size()&&v3.back().first==x) v3.back().second+=cnt;
            else v3.push_back({x,cnt});
        }
    }
    int m; cin>>m;
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        int cnt=1;
        if(x%k){
            if(v4.size()&&v4.back().first==x) v4.back().second+=cnt;
            else v4.push_back({x,cnt});
        }
        else{
            while(x%k==0){
                x/=k;
                cnt=cnt*k;
            }
            if(v4.size()&&v4.back().first==x) v4.back().second+=cnt;
            else v4.push_back({x,cnt});
        }
    }
    if(v3==v4) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
