#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1),res;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        ans+=x/k;
        x%=k;
        if(x) res.push_back(x);
    }
    sort(res.begin(),res.end());

    int l=0,r=res.size()-1;
    while(l<r){
        if(res[l]+res[r]>=k){
            l++,r--;
            ans++;
        }
        else l++;
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
