#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int k;

int get(int x){
    int l=1,r=1e10+10;
    int ans=0;
    while(l<=r){
        int mid=l+r>>1;
        int tt=mid*(mid+1)/2;
        if((mid*(mid+1)/2)<=k){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

void sol(){
    int a,b; cin>>k>>a>>b; 
    // int cnt=lower_bound(res+1,res+maxn,k)-res+1;
    // int cnt=sqrt(2*k);
    int cnt=get(k);
    // cout<<cnt<<endl;
    if(a==b){
        if(cnt%2==0) cout<<"niuniu"<<endl;
        else cout<<"niumei"<<endl;
    }
    if(a>=b+1){
        cout<<"niuniu"<<endl;
    }
    else if(b>=a+1){
        cout<<"niumei"<<endl;
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
