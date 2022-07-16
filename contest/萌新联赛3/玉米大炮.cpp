#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int __int128

using namespace std;

const int maxn=2e5+10;
int a[maxn],b[maxn];
int n,m;

inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void sol(){
    // cin>>n>>m;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        // cin>>a[i]>>b[i];
        a[i]=read(),b[i]=read();
    }

    auto check=[&](int mid){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=(1+mid/b[i])*a[i];
        }
        if(cnt>=m) return true;
        else return false;
    };

    int ans=0;
    int l=0,r=1e18+10;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    // cout<<ans<<endl;
    print(ans);

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    while(_--){
        sol();
    }

    return 0;
}
