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
    int c; cin>>c;
    int w,o=0;
    vector<int> p(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        o+=p[i];
    }
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        a[i]=c*(n-i)+x-p[i];
    }
    w=o;
    sort(all(a));
    for(int i=1;i<=n;i++){
        w=min(w,o+=a[i]-c*(i-1));
    }
    cout<<w<<endl;

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
