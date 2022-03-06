#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;

vector<pii> v[100];

bool cmp(pii a,pii b){
    if(a.first<b.first) return false;
    else if(a.first==b.first){
        if(a.second>b.second) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        int c,t; cin>>c>>t;
        v[c].push_back({t,i});
    }
    for(int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end(),cmp);
        cout<<v[i][0].second<<' ';
    }
    

    return 0;
}
