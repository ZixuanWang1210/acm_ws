#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]
using namespace std;

const int N=1e5+10;
ll Q,M;
struct node{
    int l,r;
    ll v;
} tr[4*N];
int mp[100010];

void build(int u,int l,int r){
    if(l==r) root={l,r,1};
    else{
        root={l,r,1};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}

void pushup(int u){
    root.v=((ls.v%M)*(rs.v%M))%M;
}

void modify(int u,int x,int k){
    if(root.l==x&&root.r==x){
        root={x,x,k};
    }
    else{
        int mid=root.l+root.r>>1;
        if(x<=mid) modify(u<<1,x,k);
        if(x>mid) modify(u<<1|1,x,k);
        pushup(u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        memset(tr,0,sizeof tr);
        cin>>Q>>M;
        build(1,1,Q+1);
        int idx=2,tt=1;
        while(Q--){
            int op,m;cin>>op>>m;
            if(op==1){
                modify(1,idx,m);
                mp[tt]=idx;
                idx++;
            } 
            else{
                modify(1,mp[m],1);
            }
            cout<<tr[1].v%M<<endl;
            tt++;
        }
    }
    

    return 0;
}
