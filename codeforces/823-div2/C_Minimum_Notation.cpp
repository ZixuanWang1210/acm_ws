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
    string s; cin>>s;
    vector<vector<int>> pos(10);
    for(int i=0;i<s.length();i++){
        pos[s[i]-'0'].push_back(i);
    }
    int cur=-1;
    vector<int> cnt(10);
    for(int i=0;i<10;i++){
        for(auto x:pos[i]){
            if(x>cur){
                cur=x;
                cnt[i]++;
            }
            else cnt[min(i+1,9)]++;
        }
    }
    for(int i=0;i<10;i++){
        while(cnt[i]--) cout<<i;
    }
    cout<<endl;
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
