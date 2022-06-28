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
//     int n,k,q; cin>>n>>k>>q;
//     if(q==1&&n%2==0){
//         if(k&1) k++;
//         else k--;
//         cout<<k<<endl;
//         return;
//         // cout<<(n^1)<<endl;
//         // for(int i=1;i<=n;i+=2){
//         //     cout<<i+1<<' '<<i<<" ";
//         // }
//         // return;
//     }
//     else if(q==1&&n%2!=0){
//         if(k==n){
//             cout<<n<<endl;
//             return;
//         }
//         if(k&1) k++;
//         else k--;
//         cout<<k<<endl;
//         return;
//         // n--;
//         // for(int i=1;i<=n;i+=2){
//         //     cout<<i+1<<' '<<i<<" ";
//         // }
//         // cout<<n;
//         // return;
//     }

//     q%=2;
//     if(q==1){
//         if(k&1) k++;
//         else k--;
//     }
//     // if(!q){
//     if(k==1) cout<<2;
//     else if(k==2) cout<<4;
//     else{
//         if(n&1){
//             if(k==n-1) cout<<n;
//             else if(k&1){
//                 cout<<k-2;
//             }
//             else cout<<k+2;
//             // if(k==n) cout<<n-2;
//         }
//         else{
//             if(k==n) cout<<n;
//             else if(k&1){
//                 cout<<k-2;
//             }
//             else cout<<k+2;
//         }
//     }
//     // }

    
//     cout<<endl;

// }

void sol(){
    int n,k,q; cin>>n>>k>>q;
    int t=1;
    int ans=0;
    k%=(2*n);
    if(q&1){
        if(k<=n-q){
            ans=q+k;
        }
        else{
            k=k-(n-q);
            if(k<=n) ans=n-k+1;
            else ans=k%n;
        }
    }
    else{
        if(k<=q-1){
            ans=q-k;
        }
        else{
            k=k-(q-1);
            if(k<=n) ans=k;
            else ans=(2*n-k+1);
        }
    }
    cout<<ans<<endl;

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
