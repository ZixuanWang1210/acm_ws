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

const int maxn=11000;
int biao[maxn];

void init(){
    biao[1]=1;
    for(int i=2;i<=10000+10;i++){
        biao[i]=2*biao[i-1]+1;
    }
}

void sol(){
    int n; cin>>n;
    cout<<biao[n]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    init();
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
