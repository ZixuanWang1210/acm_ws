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
const int maxn=1e6+10;
vector<int> v[maxn];

void sol(){
    int n,m; cin>>n>>m;
    map<int,int> mp;
    int f=0;
    for(int i=1;i<=m;i++) v[i].clear();
    for(int i=1;i<=m;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a; cin>>a;
            v[i].push_back(a);
        }
        if(k==1){
            mp[v[i][0]]++;
            if(mp[v[i][0]]>(m+1)/2) f=1;
        }
    }
    if(f) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++){
            int d=0,mi=1e9;
            if(v[i].size()==1){
                cout<<v[i][0]<<' ';
            }
            else{
                for(int j=0;j<v[i].size();j++){
                    mi=mp[v[i][j]];d=v[i][j];
                }
            }
            cout<<d<<' ';
            mp[d]++;
        }
        cout<<endl;
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
