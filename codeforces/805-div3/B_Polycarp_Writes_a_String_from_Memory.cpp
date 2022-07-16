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
    string s; cin>>s;
    int res=0;
    int cnt=0;
    set<char> st;
    for(int i=0;i<s.length();i++){
        char x=s[i];
        if(st.count(x)==0){
            st.insert(x);
        }
        if(st.size()==4){
            res++;
            st.clear();
            st.insert(x);
        }
        // if(st.count(x)==0){
        //     cnt++;
        //     st.insert(x);
        // }
        // if(st.size()==3) st.clear();
        // if(cnt==3){
        //     res++;
        //     cnt=0;
        // }
    }
    if(st.size()) res++;
    cout<<res<<endl;
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
