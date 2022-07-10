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

// void sol(){
//     int x; cin>>x;
//     int cnt=0;
//     while(x){
//         if(x%2==0) cnt++;
//         x/=2;
//     }
//     if(cnt&1) cout<<"Bob win"<<endl;
//     else cout<<"Alice win"<<endl;

// }
map<int,int> dev(int x){
    int res=0;
    map<int,int> mp;
    if(x<2) mp[x]++;
    for(int i=2;i<=x/i;i++){
        int cnt=0;
        // if(x%i==0) res++;
        while(x%i==0){
            cnt++;
            mp[i]++;
            x/=i;
        }
        // res^=cnt;
        // vec.push_back(cnt);
    }
    if(x>1) mp[x]++;
    // cout<<endl;
    return mp;
}

void sol(){
    int x; cin>>x;
    auto res=dev(x);
    // cout<<res<<endl;
    bool flag=true;
    int ans=0;
    for(auto x:res){
        if(x.second!=1)  flag=false;
        ans^=x.second;
    }
    int n=res.size();
    if(flag){
        if(n%2==1){
            cout<<"Bob win"<<endl;
        }
        else{
            cout<<"Alice win"<<endl;
        }
    }
    else{
        if(ans==0) cout<<"Bob win"<<endl;
        else cout<<"Alice win"<<endl;
    }
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
