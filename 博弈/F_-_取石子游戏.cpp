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

map<int,int> mp;
int n;
void sol(){
    for(int i=1;i<=47;i++){
        if(mp[i]==n){
            cout<<"Second win"<<endl;
            return;
        }
    }
    cout<<"First win"<<endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    mp[1]=1,mp[2]=1;
    for(int i=3;i<=47;i++) mp[i]=mp[i-1]+mp[i-2];
    while(cin>>n,n){
        sol();
    }

    return 0;
}
