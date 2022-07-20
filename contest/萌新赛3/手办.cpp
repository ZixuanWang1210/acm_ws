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
    int n; cin>>n;
    int x; x=n;
    unordered_map<int, int> mp;
    for(int i=2;i<=x/i;i++){
        while(x%i==0){
            mp[i]++;
            x/=i;
        }
    }
    if(x>1) mp[x]++;

    int temp=1;
    for(auto x : mp){
        temp *= (x.second + 1);
    }
    cout<<temp<<endl;

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
