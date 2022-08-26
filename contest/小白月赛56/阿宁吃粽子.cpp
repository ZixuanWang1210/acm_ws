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

// void sol(){
//     int n; cin>>n;
//     vector<int> v(100000),sum(100000);
//     for(int i=1;i<=n;i++) cin>>v[i];
//     sort(all(v));
//     for(int i=1;i<=n;i++){
//         sum[i]+=sum[i-1];
//     }
//     int zu=n/10;
//     int res=n%10;
//     int a[10]={0};

//     for(int i=0;i<10;i++) a[i]=zu;
//     for(int i=0;i<res;i++) a[i]++;

//     int idx=1;
//     int ans=0;
//     for(int i=0;i<10;i++){
//         int t=0;
//         for(int j=0;j<a[i];j++){
//             t+=v[idx++];
//         }
//         ans+=(1<<i)*t;
//     }
//      cout<<ans<<endl;
//     // int ans=0;
//     // for(int i=0;i<10;i++){
//     //     ans+=(1<<i)*(sum[zu*(i+1)]-sum[zu*i]);
//     // }
// }

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),res(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(all(v));

    // int res[1000]={0};
    int j=1,now=10;
    for(int i=0;i<10;i++){
        while(now<=n){
            res[now]=v[j];
            now+=10;
            j++;
        }
        now=i+1;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
