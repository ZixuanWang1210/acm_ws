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

struct node{
    int p,v,t;
    bool operator<(const node &t) const{
        return p<t.p;
    }
};
const int maxn=1e5+10;
int qian[maxn],hou[maxn];

void sol(){
    int n,k; cin>>n>>k;

    vector<node> v(n+1);
    for(int i=1;i<=n;i++){
        node tt;
        cin>>tt.p>>tt.v>>tt.t;
        v[i]=tt;
    }
    sort(all(v));
    // for(int i=1;i<=n;i++){
    //     cout<<v[i].p<<' '<<v[i].v<<' '<<v[i].t<<endl;;
    // }
    // cout<<endl;

    // map<int,int> mp;
    for(int i=1;i<=n;i++){
        int j=i+1;
        while(j<=n&&v[j].t==v[i].t){
            j++;
        }
        for(int ii=i;ii<=j-1;ii++){
            if(v[j].t!=v[i].t) hou[ii]=j;
            // else hou[ii]=-1;
        }
        // if(mp[v[i].t]) qian[i]=mp[v[i].t],mp[v[i].t]=i;
        // else qian[i]=-1,mp[v[i].t]=i;
        // cout<<qian[i]<<' ';
    }
    for(int i=n;i>=1;i--){
        int j=i-1;
        while(j>=1&&v[i].t==v[j].t){
            j--;
        }
        for(int ii=j+1;ii<=i;ii++){
            if(v[j].t!=v[i].t) qian[ii]=j;
            // else hou[ii]=-1;
        }
    }
    // for(int i=1;i<=n;i++) cout<<qian[i]<<' ' ;
    // cout<<endl;
    // for(int i=1;i<=n;i++) cout<<hou[i]<<' ' ;
    // cout<<endl;
    // cout<<endl;
    // mp.clear();
    // cout<<mp[v[5].t]<<endl;
    // for(int i=n;i>=1;i--){
    //     if(mp[v[i].t]) hou[i]=mp[v[i].t],mp[v[i].t]=i;
    //     else hou[i]=-1,mp[v[i].t]=i;
    //     cout<<hou[i]<<' ';
    // }
    // cout<<endl;
    int res=0,time=inf;
    for(int i=1;i<=n;i++){
        if(qian[i]!=0){
            int v1=v[qian[i]].v,v2=v[i].v,p1=v[qian[i]].p,p2=v[i].p;
            if(v1>=0&&v2>=0&&v1>v2){
                if(time>(p2-p1)/(v1-v2)) time=(p2-p1)/(v1-v2);
            }
            else if(v1>=0&&v2<=0&&(v1||v2)){
                if(time>(p2-p1)/(v1-v2)) time=(p2-p1)/(v1-v2);
            }
        }
        if(hou[i]!=n+1){
            int v2=v[hou[i]].v,v1=v[i].v,p2=v[hou[i]].p,p1=v[i].p;
            if(v1>=0&&v2>=0&&v1>v2){
                if(time>(p2-p1)/(v1-v2)) time=(p2-p1)/(v1-v2);
            }
            else if(v1>=0&&v2<=0&&(v1||v2)){
                if(time>(p2-p1)/(v1-v2)) time=(p2-p1)/(v1-v2);
            }
        }
    }
    if(time==inf) cout<<-1<<endl;
    else cout<<time<<endl;
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
