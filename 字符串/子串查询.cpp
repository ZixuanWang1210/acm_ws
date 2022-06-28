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
int n,q;
string S;
vector<int> mp[30];

void work(){
    string T; cin>>T;
    int m=T.length()-1;
    int idx=-1;
    for(int i=0;i<m;i++){
        int x=T[i]-'a';
        if(mp[x].size()==0){
            cout<<"NO"<<endl;
            return;
        }
        int tt=*upper_bound(mp[x].begin(),mp[x].end(),idx);
        if(tt<=idx){
            cout<<"NO"<<endl;
            return;
        }
        idx=tt;
        cout<<idx<<endl;
    }
    cout<<"YES"<<endl;
}

void sol(){
    cin>>n>>q>>S;
    for(int i=0;i<n;i++){
        int x=S[i]-'a';
        mp[x].push_back(i);
    }
    
    while(q--){
        work();
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
