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

const int maxn=1e5+10;

void sol(){
    string s,t; cin>>s>>t;
    s=" "+s;
    int len=s.length()-1;

    vector<vector<int>> nxt(maxn,vector<int>(26,inf));
    // set<char> st;
    // for(int i=1;i<=len;i++) st.insert(s[i]);
    // for(auto x:t) if(!st.count(x)) {
    //     cout<<-1<<endl;
    //     return;
    // }

    for(int i=len;i>0;i--){
        for(int j=0;j<26;j++) nxt[i-1][j]=nxt[i][j];
        nxt[i-1][s[i]-'a']=i;
    }

    int idx=1;
    int res=1;
    for(auto x:t){
        if(idx==len+1){
            idx=0;
            res++;
        }
        if(nxt[idx][x-'a']==inf){
            idx=0;
            res++;
        }
        if(nxt[idx][x-'a']==inf&&idx==0){
            idx=0;
            res++;
        }
        idx=nxt[idx][x-'a']+1;
    }
    if(res>=inf) cout<<-1<<endl;
    else cout<<res<<endl;
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
