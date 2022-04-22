#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=2e5+10;
int a[maxn],b[maxn];
int n;

bool check(int x){
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=n;i>=3;i--){
        int h=min(a[i]/3,(b[i]-x)/3);
        b[i-1]+=h,b[i-2]+=2*h;
    }
    for(int i=1;i<=n;i++) {
        if(b[i]<x) return false;
    }
    return true;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=1,r=1e10;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
