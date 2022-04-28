#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
const int maxn=2e5+10;
int b[maxn],a[maxn];

// void sol(){
//     int n ; cin>>n;
//     vector<int> v(n+1);
//     int cnt[maxn]={0};
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         cnt[v[i]]++;
//     }
//     map<int,int> mp1,mp2;
//     for(int i=1;i<=n;i++){
//         int now=min(i,n-i+1);
//         if(now>)
//         mp2[v[i]]=max(mp2[v[i]],min(i,n-i+1));
//         if(mp1[v[i]]==0) mp1[v[i]]=min(i,n-i+1);
//         else if(mp1[v[i]]<=mp2[v[i]]) mp1[v[i]]=mp2[v[i]];
//     }

//     int ans=-1;
//     for(auto x:mp1){
//         int id=x.first;
//         if(cnt[id]==1) continue;
//         ans=max(ans,mp2[id]+mp1[id]-1);
//     }
//     // if(unique(v.begin()+1,v.begin()+1+n)==v.begin()+1+n){
//     //     cout<<-1<<endl;
//     //     return;
//     // }
//     cout<<ans<<endl;
// }

void sol(){
    int n; cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b[a[i]]){
            ans=max(ans,b[a[i]]+n-i);
        }
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++) b[a[i]]=0;
    cout<<(ans>0?ans:-1)<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
