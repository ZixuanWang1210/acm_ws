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
const int maxn=5e5+10;
int a[maxn];

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        a[x]+=n*i;
    }

    sort(a+1,a+1+n);

    int cnt=min(5ll,n);

    for(int i=1;i<=cnt;i++){
        a[i]%=n;
    }

    sort(a+1,a+1+cnt);
    if(a[1]==0){
        for(int i=2;i<=cnt;i++){
            cout<<a[i]%n<<' ';
        }
        cout<<n;
    }
    else{
        for(int i=1;i<=cnt;i++){
            if(a[i]%n) cout<<a[i]%n<<' ';
            else cout<<n<<' ';
        }
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
