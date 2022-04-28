#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

// void sol(){
//     int n; cin>>n;
//     vector<int> v(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//     }
//     int cnt=1;
//     int ans=0;
//     int res=0;
//     map<int,int> mp;
//     for(int i=2;i<=n;i++){
//         if(v[i-1]==v[i]) cnt++;
//         else{
//             if(cnt==1) continue;
//             if(cnt==2) res++;
//             else ans+=max(1ll,cnt-3),res++;
//             cnt=1;
//         }
//     }
//     if(cnt==2) res++;
//     if(cnt!=1) ans+=max(1ll,cnt-3),res++;
//     ans+=res-1;
//     cout<<ans<<endl;
// }
void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int bg=0,ed=-0x3f3f3f3f;
    for(int i=1;i<=n-1;i++){
        // if(i<=n-2) if(bg==0&&v[i]==v[i+1]==v[i+2]) bg=i+2;
        // if(i<=n-2) if(v[i]==v[i+1]==v[i+2]) ed=max(ed,i);
        if(v[i]==v[i+1]&&bg==0) bg=i+1;
        if(v[i]==v[i+1]) ed=max(ed,i);
    }
    // cout<<bg<<' '<<ed<<endl;
    if(ed==-0x3f3f3f3f||bg==ed+1){
        cout<<0<<endl;
        return;
    }
    else{
        cout<<max(1ll,ed-bg)<<endl;
        return;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
