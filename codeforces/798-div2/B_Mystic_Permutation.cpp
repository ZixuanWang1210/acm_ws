#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),res(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        res[i]=i;
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]!=res[i]) continue;
        if(i==n) swap(res[i],res[i-1]);
        else swap(res[i],res[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;

}

// void sol(){
//     int n; cin>>n;
//     set<int> st;
//     for(int i=1;i<=n;i++){
//         st.insert(i);
//     }
//     for(int i=1;i<=n;i++){
//         int x; cin>>x;
//         int ans=*st.lower_bound(0);
//         if(ans==x){
//             st.erase(x);
//             ans=*st.lower_bound(0);
//             cout<<ans<<' ';
//             st.erase(ans);
//             st.insert(x);
//         }
//         else{
//             cout<<ans<<' ';
//             st.erase(ans);
//         }
//     }
//     cout<<endl;

// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
