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

void sol(){
    int n,a,b; cin>>n>>a>>b;
    vector<bool> v(n+1);
    vector<int> res;
    // if(a+2/n>=b){
    //     cout<<-1<<endl;
    //     return;
    // }
    
    res.push_back(a);
    for(int i=n;i>=1;i--){
        if(i==a||i==b) continue;
        res.push_back(i);
    }
    res.push_back(b);
    // for(int i=n,cnt=2;cnt<=n/2;cnt++,i--){
    //     if(i==b) cnt--,continue;


    // }
    // for(int i=a,cnt=1;cnt<=n/2;cnt++,i++){
    //     // cout<<i<<" ";
    //     res.push_back(i);
    //     v[i]=true;
    // }
    // for(int i=1;i<=n;i++){
    //     if(!v[i]) res.push_back(i);
    // }
    if(*min_element(res.begin(),res.begin()+n/2)!=a||*max_element(res.begin()+n/2,res.end())!=b){
        cout<<-1<<endl;
        return;
    }
    for(auto x:res){
        cout<<x<<" ";
    }
    cout<<endl;

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
