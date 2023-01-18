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

int n,m; 
const int maxn=5e5+10;

int p[maxn];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
bool merge(int x,int y){
    x=find(x),y=find(y);
    p[x]=y;
    return true;
}

void sol(){
    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i;
    while(m--){
        int u,v; cin>>u>>v;
        merge(u,v);
    }

    set<int> st;
    int id;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x!=0){
            st.insert(find(i));
            id=find(i);
        }
        mp[find(i)]++;
    }

    int ans=0;
    if(st.size()>1){
        cout<<0<<endl;
        return;
    }
    else if(st.size()==0){
        for(auto x:mp){
            ans+=x.second*x.second;
        }
        cout<<ans<<endl;
        return;
    }
    else{
        ans=mp[id]*mp[id];
        cout<<ans<<endl;
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
