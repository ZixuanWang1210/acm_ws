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
    int n,m,t; cin>>n>>m>>t;
    vector<pii> vec;
    map<int,int> mp;
    for(int i=1;i<=m;i++){
        int a,b; 
        cin>>a>>b;
        // vec.push_back({a,a+b});
        mp[a]=max(mp[a],a+b);
    }

    for(auto x:mp){
        vec.push_back({x.first,x.second});
    }

    sort(_all(vec));

    int len=t;
    int mxlen=-1,idx=-1;
    int res=0;
    for(int i=0;i<vec.size();i++){
        // dian-=vec[i].first;
        int dis=vec[i].first;
        if(len>=dis){
            if(mxlen<vec[i].second){
                mxlen=vec[i].second;
                idx=i;
            }
        }
        else{
            if(mxlen<=len){
                cout<<-1<<endl;
                return;
            }
            len=mxlen;
            idx=-1;
            res++;
            i--;
        }
    }
    cout<<res<<endl;


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
