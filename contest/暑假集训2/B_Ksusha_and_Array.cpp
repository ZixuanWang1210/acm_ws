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
    vector<int> v(n+1);
    set<int> st;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    for(int i=2;i<=n;i++){
        v[i]=__gcd(v[i],v[i-1]);
    }
    if(st.count(v[n])){
        cout<<v[n]<<endl;
    }
    else cout<<-1<<endl;

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
