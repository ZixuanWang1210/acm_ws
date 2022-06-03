#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int lowbit(int x){
    return x&-x;
}

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int fg=0;
    int cnt=0;
    int mn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]&1) fg=1;
        else cnt++;
        mn=min(mn,lowbit(v[i]));
    }
    int ans=0;
    if(fg==0){
        
        while(mn%2==0){
            mn>>=1;
            ans++;
        }

        ans+=cnt-1;
        cout<<ans<<endl;
    }
    else{
        cout<<cnt<<endl;
    }
    


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
