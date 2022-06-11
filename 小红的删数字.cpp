#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int x; cin>>x;
    int re=x;
    set<int> st;
    int sum=0;
    while(x){
        int t=x%10;
        st.insert(t);
        sum+=t;
        x/=10;
    }
    if(sum%3==0){
        if(st.count(3)==1){
            
        }
    }
    if(st.count(sum%3)==1){
        if(x>=10&&x<100){
            cout<<"kou"<<endl;
            return;
        }
        cout<<"yukari"<<endl;
    }

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
