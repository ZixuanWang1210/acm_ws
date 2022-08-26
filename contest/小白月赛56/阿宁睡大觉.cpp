#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,pair<int,int>>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;
vector<pii> v;

void sol(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int l=-1,r=-1;
    vector<pii> v;
    for(int i=0;i<s.length();i++){
        if(s[i]=='Z'){
            if(l!=-1) v.push_back({r-l+1,{l,r}}),l=-1,r=-1;
        }
        else{
            if(l==-1) l=i,r=i;
            r=i;
        }
    }

    sort(_all(v));

    for(int i=0;i<v.size();i++){
        if(v[i].second.first==0||v[i].second.second==n-1) continue;
        int len=v[i].second.second-v[i].second.first+1;
        if(len<=k){
            k-=len;
            for(int j=v[i].second.first;j<=v[i].second.second;j++){
                s[]=' ';
            }
        }
        else break;
    }

    string ss;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ') ss=ss+s[i];
    }
    cout<<ss<<endl;
    int ans=0;
    for(int i=0;i<ss.length();i++){
        int a=0,b=0;
        a=ss[i]=='Z',b=ss[i+1]=='Z';
        ans+=a*b;
    }
    cout<<ans<<endl;
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
