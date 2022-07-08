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

const int maxn=1e5+10;
int cnt0[maxn],cnt1[maxn];

int q_mi(int a,int b,int p){
    int res=1;
    
    while(b){
        if(b&1) res*=a,res%=p;
        a*=a;
        a%=p;
        b>>=1;
    }
    
    return res;
}


void sol(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cnt0[i]=cnt0[i-1]+(s[i]=='0');
        cnt1[i]=cnt1[i-1]+(s[i]=='1');
    }

    while(q--){
        int l,r; cin>>l>>r;
        int c1=cnt1[r]-cnt1[l-1];
        int c0=cnt0[r]-cnt0[l-1];
        // cout<<c1<<' '<<c0<<endl;
        int res=q_mi(2,c1,mod)-1;
        res%=mod;
        int res2=q_mi(2,c0,mod)%mod;

        // res=res*max(1ll,c0+1)%mod;
        // res=res+c0*(c0-1)%mod*q_mi(2,mod-2,mod)%mod;
        // res%=mod;
        cout<<res*res2%mod<<endl;
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
