#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
// #define ll long long
// #define int long long

using namespace std;

const int maxn=1e5+10;
int a[maxn],s1[maxn],s2[maxn];
int n;

void sol(){
    cin>>n;
    string s; 
    cin>>s;
    for(int i=0;i<s.length();i++){
        a[i+1]=s[i]-'0';
    }

    for(int i=1;i<=n;i++){
        if(a[i]==1) s1[i+1]++;
    }

    
    for(int i=1;i<=n;i++){
        s1[i]+=s1[i-1];
        s1[i]%=mod;
    }
    for(int i=1;i<=n;i++){
        s1[i]+=s1[i-1];
        s1[i]%=mod;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) ans=(ans+s1[i])%mod;
    }
    cout<<ans<<endl;

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
