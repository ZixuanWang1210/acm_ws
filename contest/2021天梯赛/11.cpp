#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,vector<int>>
using namespace std;

int n,k,m;
map<vector<int>,int> mp;
struct node{
    int cnt;
    vector<int> v;
};

bool cmp(node &a,node &b){
    if(a.cnt!=b.cnt){
        return a.cnt>b.cnt;
    }
    else return a.v<b.v;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        vector<int> t;
        for(int j=1;j<=m;j++){
            int x; cin>>x;
            t.push_back(x);
        }
        mp[t]++;
    }
    vector<node> v;
    cout<<mp.size()<<endl;
    for(auto x:mp){
        v.push_back({x.second,x.first});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x:v){
        cout<<x.cnt<<' ';
        // for(auto t:x.v){
        for(int i=0;i<x.v.size();i++){
            int t=x.v[i];
            cout<<t;
            if(i!=x.v.size()-1) cout<<' ';
        }
        cout<<endl;
    }
    

    return 0;
}
