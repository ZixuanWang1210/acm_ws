#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define P 998244353
// #define long long long long
// #define int long long

using namespace std;

const int maxn=1e7+10;
long long fact[maxn], infact[maxn];

long long qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(long long)res*a%p;
        a=(long long)a*a%p;
        k>>=1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = (long long)fact[i - 1] * i % P;
        infact[i] = (long long)infact[i - 1] * qmi(i, P - 2, P) % P;
    }
}

int C(int a,int b){
    return (long long)fact[a] * infact[b] % P * infact[a - b] % P;
}

void sol(){
    int n,x,y,z; cin>>n>>x>>y>>z;
    int res=0;
    res+=C(x,n),res%=P,res+=C(y,n-x),res%=P,res+=C(z,n-x-y),res%=P;
    int m=n-x-y-z;
    if(m<0||m&1){
        cout<<-1<<endl;
        return;
    }
    res+=fact[x+y+z+m]*infact[x+y+z]%P;
    res%=P;
    cout<<res<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    init();
    while(_--){
        sol();
    }

    return 0;
}
