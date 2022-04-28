#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int res[20]={0};
    for(int i=1;i<=n;i++){
        int buf,dif; cin>>buf>>dif;
        res[dif]=max(res[dif],buf);
    }
    int ans=0;
    for(int i=1;i<=10;i++){
        // cout<<res[i]<<" ";
        if(res[i]==0){
            cout<<"MOREPROBLEMS"<<endl;
            return;
        }
        else ans+=res[i];
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
