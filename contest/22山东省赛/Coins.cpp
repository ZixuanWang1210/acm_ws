#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn = 5e6+10;
int dp1[maxn], dp2[maxn];

void init(){
    for(int i=1;i<=5e6;++i)dp1[i]=1e18,dp2[i]=1e18;
    for(int i=0;i<=5e6;++i){
        if(i>=2)dp1[i]=min(dp1[i],dp1[i-2]+1);
        if(i>=3)dp1[i]=min(dp1[i],dp1[i-3]+1);
        if(i>=17)dp1[i]=min(dp1[i],dp1[i-17]+1);
        if(i>=19)dp1[i]=min(dp1[i],dp1[i-19]+1);
        if(i>=5)dp2[i]=min(dp2[i],dp2[i-5]+1);
        if(i>=7)dp2[i]=min(dp2[i],dp2[i-7]+1);
        if(i>=11)dp2[i]=min(dp2[i],dp2[i-11]+1);
        if(i>=13)dp2[i]=min(dp2[i],dp2[i-13]+1);
    }
}

void sol() {
    int x; cin>>x;
    if(x>=5e6+10) cout<<"A"<<endl;
    else if(dp1[x]>1e9&&dp2[x]>1e9) cout<<-1<<endl;
    else if(dp1[x]>1e9&&dp2[x]<1e9) cout<<"A"<<endl;
    else if(dp1[x]==dp2[x]) cout<<"both"<<endl;
    else if(dp1[x]<dp2[x]) cout<<"A"<<endl;
    else cout<<"B"<<endl;
}   

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        sol();
    }

    return 0;
}
