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
const int maxn=1e6+10;
int v[maxn],s[maxn];
int mp[maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }

    int res=0;
    // map<int,int> mp;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j*j<=s[i];j++){
            res+=mp[s[i]-j*j];
        }
        mp[s[i]]++;
    }
    cout<<res<<endl;

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
