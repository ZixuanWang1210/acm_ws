#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=5e5+10;
int a[maxn];
int n;
int t;
int b[maxn];

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=INT64_MAX;
    for(int i=1;i<=n;i++) b[i]=a[i+1]-a[i];
    // for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    cout<<endl;
    cin>>t;
    while(t--){
        int x; cin>>x;
        int cnt=upper_bound(b+1,b+1+n,x)-b;
        // cout<<cnt<<endl;
        int base=a[1];

        cout<<a[cnt]-a[1]+(n-cnt+1)*x<<endl;
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
