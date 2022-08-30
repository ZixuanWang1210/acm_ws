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
    int n,m; cin>>n>>m;
    vector<int> v(n+2);
    v[0]=v[n+1]=-1;
    int suf=1,sum=1;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=2;i<=n;i++){
        if(v[i]==v[i-1]) suf++;
        else suf+=i;
        sum+=suf;
    }
    while(m--){
        int x,y; cin>>x>>y;
        if(v[x]==y){
            cout<<sum<<endl;
            continue;
        }
        if(v[x-1]!=v[x]&&v[x-1]==y) sum-=(n-x+1)*(x-1);
        if(v[x-1]==v[x]&&v[x-1]!=y) sum+=(n-x+1)*(x-1);

        if(v[x+1]!=v[x]&&v[x+1]==y) sum-=(n-x)*(x);
        if(v[x+1]==v[x]&&v[x+1]!=y) sum+=(n-x)*(x);
        cout<<sum<<endl;
        v[x]=y;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
