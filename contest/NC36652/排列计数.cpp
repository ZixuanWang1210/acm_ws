#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
// #define ll long long
#define int long long

using namespace std;

const int maxn=1e7+10;
int cc[maxn];

int qmi(int a,int b,int p){
    long long res=1;
    while(b){
        if(b&1) res=a*res%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}

void sol(){
    int n; cin>>n;
    cc[1]=1;
    for(int i=2;i<=2*n;i++){
        cc[i]=cc[i-1]*i;
        cc[i]%=mod;
    }
    cout<<cc[2*n]*qmi(2,mod-2,mod)%mod<<endl;
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
