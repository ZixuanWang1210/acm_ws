#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define piiii pair<pair<int,int>,pair<int,int>>
using namespace std;

void sol(){
    int n,m,h,q;
    cin>>n>>m>>h>>q;
    unordered_map<int,piii> mp;
    multiset<pii> mts;
    int idx=0;
    while(q--){
        int op; cin>>op;
        int x,y,z; cin>>x>>y>>z;
        if(op==1){
            mp[++idx]={x,{y,z}};
            mts.insert({x+y+z,idx});
        }
        else{
            int dt=x+y+z;
            auto x=
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
