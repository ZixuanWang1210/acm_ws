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

const int maxn=3100;
int g[maxn][maxn];
bitset<3000> bs[maxn];

void sol(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string tt; cin>>tt;
        for(int j=0;j<tt.length();j++){
            int x=tt[j]-'0';
            g[i][j]=x;
            bs[i][j]=x;
            
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(bs[i][j]==0) continue;
            // cout<<i<<' '<<j<<endl;
            bitset<3000> res;
            res=bs[i]&bs[j];
            ans+=res.count(); 
            // cout<<res.count()<<endl;
        }
    }
    cout<<ans/3<<endl;

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
