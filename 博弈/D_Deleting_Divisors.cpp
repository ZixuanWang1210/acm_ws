#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

bool is_prime(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}

void sol(){
    int n; cin>>n;
    if(n==2||n==8) cout<<"Bob"<<endl;
    else{
        if(n&1) cout<<"Bob"<<endl;
        else{
            int cnt=0;
            while(n%2==0) cnt++,n/=2;
            if(n==1&&cnt%2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }

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
