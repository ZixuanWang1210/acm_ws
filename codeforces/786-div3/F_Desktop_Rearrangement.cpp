#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=1e4+10;
char mp[maxn][maxn];

void sol(){
    int n,m,q; cin>>n>>m>>q;
    int cnt[maxn]={0};
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='*') tot++,cnt[j]++;
        }
    }

    while(q--){
        int x,y; cin>>x>>y;
        if(mp[x][y]=='*') tot--,cnt[y]--,mp[x][y]='.';
        else tot++,cnt[y]++,mp[x][y]='*';

        int l=tot/n,res=tot-n*l;
        int t=0;
        for(int i=1;i<=l;i++) t+=cnt[i];
        for(int i=1;i<=res;i++) if(mp[i][l+1]=='*') t++;
        cout<<tot-t<<endl;
    }
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_; 
    while(_--){
        sol();
    }

    return 0;
}
