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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using namespace std;

void sol(){
    int n; cin>>n;
    int q; cin>>q;
    vector<int> v(n+1);
    unordered_map<int,int,custom_hash> a,b;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(a[v[i]]==0){
            a[v[i]]=i;
        }
        if(b[v[i]]==0){
            b[v[i]]=i;
        }

        a[v[i]]=max(a[v[i]],i);
        b[v[i]]=min(b[v[i]],i);
    }
    while(q--){
        int l,r; cin>>l>>r;
        if(a[l]==0||a[r]==0){
            cout<<"NO"<<endl;
        }
        else{

        if(b[l]>a[r]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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
