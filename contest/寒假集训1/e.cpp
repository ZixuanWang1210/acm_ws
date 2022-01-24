#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
using namespace std;

void sol(){
    int n, m;
    cin >> n>>m;
    int ans = 0;
    if(m==1){
        if(n==1){
            cout << 1<< endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }
    // while(n){
    //     n-=m;
    //     ans ++;
    //     if(n<=0)break;
    //     ans++;n+=1;
    // }

    int t = (n-m)%(m-1);
    if(t==0) t = (n-m)/(m-1);
    else t= (n-m)/(m-1) + 1;

    ans = 1+t*2;

    cout <<ans<<endl;;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        sol();
    }
    return 0;
}
