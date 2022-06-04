#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int mod=1e9+7;

int qmi(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),s(n+1),as(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
        s[i]%=mod;
    }
    int re=0;
    for(int i=1;i<=n;i++){
        if(i<=ceil((double)n/2)){
            as[i]=(as[i-1]+s[n-i+1]-s[i-1]+mod)%mod;
        }
        else{
            as[i]=as[n+1-i];
        }
        // cout<<as[i]<<" ";
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+as[i]*qmi(i,mod-2);
        ans%=mod;
    }
    cout<<ans<<endl;
    

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
