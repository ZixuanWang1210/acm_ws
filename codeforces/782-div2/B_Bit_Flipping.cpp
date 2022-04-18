#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

// void sol(){
//     int n,k; cin>>n>>k;
    
//     vector<int> v(n+1),res(n+1);
//     for(int i=1;i<=n;i++) cin>>v[i];

//     for(int i=1;i<=n;i++){
//         if(v[i]==0&&k&1||v[i]==1&&k%2==0){
//             if(i==n&&k%2==1){
//                 res[i]=1,v[i]=0;
//                 k--;
//             }
//             else res[i]=0,v[i]=1;
//         }
//         else{
//             if(i==n&&k%2==0){
//                 res[i]=0,v[i]=0;
//             }
//             else if(k==0) res[i]=0,v[i]=0;
//             else res[i]=1,v[i]=1;
//         }
//     }

// }
void sol(){
    int n,k; cin>>n>>k;
    
    vector<int> v(n+1),res(n+1),cnt(n+1);
    string s; cin>>s;
    for(int i=0;i<s.length();i++){
        v[i+1]=s[i]-'0';
    }
    // for(int i=1;i<=n;i++) cin>>v[i];

    int now=0;
    for(int i=1;i<=n;i++){
        if(i==n){
            cnt[i]+=k;
            now+=k;
            break;
        }
        if((v[i]==1&&now%2==0&&k&1&&k>0)||(v[i]==0&&now%2==1&&k&1&&k>0)){
            cnt[i]++;
            now++;
            k--;
        }
        else if((v[i]==0&&now%2==0&&k%2==0&&k>0)||(v[i]==1&&now%2==1&&k%2==0&&k>0)){
            cnt[i]++;
            now++;
            k--;
        }
    }
    for(int i=1;i<=n;i++){
        int tt;
        if((now-cnt[i])%2==0) tt=0;
        else tt=1;

        int x=v[i]^tt;
        cout<<x;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<' ';
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
