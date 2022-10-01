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

void sol(){
    int n; cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=b[i]-a[i];
    }
    sort(all(a));

    int cnt=0;
    for(int i=1;i<a.size();i++){
        if(a[i]<0){
            auto x=lower_bound(all(a),-a[i]);
            if(x==a.end()) continue;
            if(*x>=a[i]) {
                cnt++;
                a.erase(x);
            }
        }
    }
    int t=0;
    for(int i=1;i<a.size();i++){
        if(a[i]>=0) t++;
    }
    cnt+=t/2;
    cout<<cnt<<endl;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
