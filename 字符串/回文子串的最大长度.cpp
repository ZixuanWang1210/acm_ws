#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define LL long long
// #define int long long

using namespace std;

const int maxn=1e6+10;
LL p[maxn],hasL[maxn],hasR[maxn];
string str;

int getHas(int l,int r,LL has[]){
    if(l>r) swap(l,r);
    return (has[r]-has[l-1]*p[r-l+1]%mod)%mod;
}

void sol(){
    // cin>>str;
    int n=str.length();
    str.resize(2*n);
    for(int i=2*n;i;i-=2){
        str[i]=str[i/2];
        str[i-1]='#';
    }
    // for(int i=0;i<str.length();i++){
    //     cout<<str[i];
    // }
    // cout<<endl;
    n-=1;
    n*=2;

    int base=1331;
    p[0]=1;
    for(int i=1,j=n;j<=n;i++,j--){
        hasL[i]=hasL[i-1]*base%mod+str[i];
        hasL[i]%=mod;
        hasR[j]=hasR[j+1]*base%mod+str[j];
        hasR[j]%=mod;
        p[i]=p[i-1]*base%mod;
    }

    int res=0;
    for(int i=1;i<=n;i++){
        int l=0,r=min(i-1,n-i);
        int ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(getHas(i-mid,i-1,hasL)==getHas(n-(i+1)+1,n-(i+mid)+1,hasR)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(str[i-1]<='z') res=max(res,ans+1);
        else res=max(res,ans);
    }
    cout<<res<<endl;


}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int _=1;
    int T=0;
    // cin>>_;
    while(cin>>str,str!="END"){
        cout<<"Case "<<++T<<": ";
        sol();
    }

    return 0;
}
