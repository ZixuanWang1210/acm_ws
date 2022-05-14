#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    set<pii> st;
    set<pii> ans;
    int n,m,k;
    cin>>n>>m>>k;

    vector<pii> v(k+1);

    for(int i=1;i<=k;i++){
        int x,y; cin>>x>>y;
        x*=10,y*=10;
        v[i]={x,y};
    }

    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            int mx=v[i].first+v[j].first>>1;
            int my=v[i].second+v[j].second>>1;

            if(st.count({mx,my})==1){
                double ax=mx/10,ay=my/10;
                cout<<"YES "<<fixed<<setprecision(1)<<ax<<" "<<ay<<endl;
                return;
            }
            else st.insert({mx,my});
        }
    }

    cout<<"NO"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
