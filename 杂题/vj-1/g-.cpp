#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
int d[1100]={0};
bool mp[1100][1100]={0};
int n,m;

void sol(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b; 
        d[a]++,d[b]++,mp[a][b]=1,mp[b][a]=1;
    }
    int ans=0;
    while(1){
        bool ok=false;
        vector<int> v;
        ans++;
        for(int i=1;i<=n;i++){
            if(d[i]==1) v.push_back(i),d[i]--,ok=true;
        }
        for(auto x:v){
            for(int j=1;j<=n;j++){
                if(mp[x][j]) d[j]--;
            }
        }
        if(!ok) break;
    }
    cout<<ans-1<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
