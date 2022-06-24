#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=5e4+10;
int id[maxn],a[maxn],b[maxn],s[maxn];
int n;
int len;

void add(int l,int r,int x){
    int sid=id[l],eid=id[r];
    if(sid==eid){
        for(int i=l;i<=r;i++){
            a[i]+=x,s[sid]+=x;
        }
        return;
    }
    for(int i=l;id[i]==sid;i++) a[i]+=x,s[sid]+=x;
    for(int i=sid+1;i<eid;i++) b[i]+=x,s[i]+=x*len;
    for(int i=r;id[i]==eid;i--) a[i]+=x,s[eid]+=x;
}

int query(int l,int r,int p){
    int sid=id[l],eid=id[r];
    int ans=0;
    if(sid==eid){
        for(int i=l;i<=r;i++) ans=(ans+a[i]+b[sid])%p;
        return ans;
    }
    for(int i=l;id[i]==sid;i++){
        ans=(ans+a[i]+b[sid])%p;
    }
    for(int i=sid+1;i<eid;i++) ans=(ans+s[i])%p;
    for(int i=r;id[i]==eid;i--) ans=(ans+a[i]+b[eid])%p;
    return ans;
}

void sol(){
    cin>>n;
    len=sqrt(n);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        id[i]=(i-1)/len+1;
        s[id[i]]+=a[i];
    }

    for(int i=1;i<=n;i++){
        int op,l,r,c;
        cin>>op>>l>>r>>c;
        if(op==0) add(l,r,c);
        else cout<<query(l,r,c+1)<<endl;
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
