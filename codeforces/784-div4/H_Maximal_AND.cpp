#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    int cnt[100]={0};
    int _max=-1;
    int base=-1;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(base==-1) base=x;
        else base=base&x;
        int idx=0;
        while(x){
            int t=x&1;
            // cout<<t<<endl;
            cnt[idx]+=t;
            _max=max(_max,idx);
            x>>=1;
            idx++;
        }
    }

    for(int i=30;i>=0;i--){
        cnt[i]=n-cnt[i];
        // cout<<cnt[i]<<' ';
        if(cnt[i]<=k){
            k-=cnt[i];
            base|=(1<<i);
        }
    }
    cout<<base<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
