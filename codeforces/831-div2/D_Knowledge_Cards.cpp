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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(k+1);
    if(n>m) swap(n,m);
    for(int i=1;i<=k;i++) cin>>v[i];
    set<int> st;
    int now=k,up=n*m-3;
    for(int i=1;i<=k;i++){
        if(v[i]==now){
            now--;
            while(now>=1&&st.count(now)){
                st.erase(now);
                now--;
            }
            continue;
        }
        st.insert(v[i]);
        if(st.size()==up){
            cout<<"TIDAK"<<endl;
            return;
        }
    }
    cout<<"YA"<<endl;
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
