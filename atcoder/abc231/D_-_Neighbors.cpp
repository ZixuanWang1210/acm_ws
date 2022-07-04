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
const int maxn=1e6+10;
int d[maxn];

int p[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void sol(){

    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;

        int aa=find(a),bb=find(b);
        if(aa==bb){
            cout<<"No"<<endl;
            return;
        }
        p[aa]=bb;

        d[a]++,d[b]++;
    }

    for(int i=1;i<=n;i++){
        if(d[i]>2){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;

    // for(int i=1;i<=n;i++){
    //     cout<<d[i]<<endl;
    // }
    // int cnt=0;
    // for(int i=1;i<=n;i++){
    //     if(d[i]>2){
    //         cout<<"No"<<endl;
    //         return;
    //     }
    //     if(d[i]==1){
    //         cnt++;
    //     }
    // }
    // if(cnt!=2&&m!=0){
    //     cout<<"No"<<endl;
    //     return;
    // }
    // cout<<"Yes"<<endl;
    // return;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
