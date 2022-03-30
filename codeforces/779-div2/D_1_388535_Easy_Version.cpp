#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long

using namespace std;

void sol(){
    int l,r; cin>>l>>r;
    int len=r-l+1;
    vector<int> v(len*2);
    unordered_set<int> st;
    for(int i=1;i<=len;i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    if(l==r){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=len;i++){
        int x=v[i];
        x^=1;
        if(st.find(x)!=st.end()){
            cout<<x<<endl;
            return ;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
