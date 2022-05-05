#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    vector<int> v[30];
    set<char> st;
    for(int i=0;i<s.length();i++){
        v[s[i]-'a'].push_back(i);
        st.insert(s[i]);
    }


    int cnt=st.size();
    for(int i=0;i<26;i++){
        for(int j=1;j<v[i].size();j++){
            if(v[i][j]-v[i][j-1]<cnt){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;


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
