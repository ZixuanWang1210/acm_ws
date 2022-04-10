#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e5+10;
bool vis[maxn];

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),cnt(n+1);
    vector<int> b;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        cnt[v[i]]++;
    }

    int mex=0,last=0;
    for(int i=1;i<=n;i++){
        vis[v[i]]=true;
        while(vis[mex]) mex++;
        cnt[v[i]]--;
        if(cnt[mex]==0){
            b.push_back(mex);
            mex=0;
            for(int j=last;j<=i;j++){
                vis[v[j]]=false;
            }
            last=i+1;
        }
    }
    cout<<b.size()<<endl;
    for(auto x:b) cout<<x<<' ';
    cout<<endl;
    return;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
