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

const int maxn=2e6+10;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int n;
int din[maxn];
int k;


void sol(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x; cin>>x; din[x]++;
    }
    for(int i=1;i<=n;i++){
        cout<<(din[i]>=k?din[i]:-1)<<' ';
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
