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

const int maxn=1e6+10;
int m;
int a[maxn];
void init(){
    a[0]=1;
    for(int i=1;i<=maxn;i++){
        a[i]=a[i-1]*i%m;
    }
}
void sol(){
    int n; cin>>n;
    int res=1;
    for(int i=2;i<=n;i++){
        res*=i;
        if(res>=m){
            cout<<0<<endl;
            return;
        }
    }
    cout<<a[res]%m<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    cin>>m;
    init();
    while(_--){
        sol();
    }

    return 0;
}
