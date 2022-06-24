#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e5+10;
int a[maxn];
int n,q;
int R[maxn];
int st[maxn][35];

void sol(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=inf;

    for(int i=n;i>=1;i--){
        R[i]=i;
        while(a[i]>=a[R[i]+1]) R[i]=R[R[i]+1];
    }

    for(int i=1;i<=n;i++){
        st[i][0]=R[i]+1;
    }
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
            if(st[j][i-1]>n) st[j][i]=1e9;
            else st[j][i]=st[st[j][i-1]][i-1];
        }
    }

    // for(int i=1;i<=17;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<st[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int l,r; cin>>l>>r;
        int ans=0;
        for(int i=17;i>=0;i--){
            if(st[l][i]<=r) l=st[l][i],ans|=(1<<i);
        }
        cout<<ans+1<<endl;
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
