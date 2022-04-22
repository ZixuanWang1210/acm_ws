#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    map<int,int> cnt;
    vector<int> ans;
    bool bz=false;
    int res=0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        cnt[x]++;
        if(cnt[x]==3&&res==0){
            res=x;
        }
    }
    if(res) cout<<res<<endl;
    else cout<<-1<<endl;  
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
