#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=5e5+10;
int a[maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int idx=2;
    for(int i=1;i<=n;i++){
        if(a[1]==i) cout<<1<<' ';
        else cout<<idx++<<' ';
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
