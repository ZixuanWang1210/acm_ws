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
const int maxn=2e6+10;
int a[maxn];
void sol(){
    int n; cin>>n;
    int cnt[30]={0};
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        int idx=0;
        while(x){
            if(x&1) cnt[idx]++;
            idx++;
            x>>=1;
        }
    }

    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=0;j<30;j++){
            if(n-cnt[j]<i) {
                ans+=(1<<j);
            }
        }
        cout<<ans<<' ';
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
