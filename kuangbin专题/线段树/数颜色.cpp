#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=10000;
int st[maxn];
int n;
struct node{
    int l,r;
    int col;
} tr[maxn<<2];


#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    if(ls.col==rs.col) root.col=ls.col;
    else root.col=-1;
}

void pushdown(int u){
    if(root.col!=-1){
        ls.col=rs.col=root.col;
    }
}

void build(int u,int l,int r){
    if(l==r) root={l,r,-1};
    else{
        tr[u]={l,r,-1};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        root.col=k;
    }
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

void query(int u,int l,int r){
    if(root.col!=-1){
        for(int i=tr[u].l;i<=tr[u].r;i++){
            st[i]=tr[u].col;
        }
    }
    if(l==r) return;
    else{
        pushdown(u);
        int mid=l+r>>1;
        query(u<<1,l,mid),query(u<<1|1,mid+1,r);
        return;
    }
}

void sol(){
    build(1,1,8001);
    for(int i=1;i<=n;i++){
        int l,r,c; cin>>l>>r>>c;
        l++;
        modify(1,l,r,c);
    }
    memset(st,-1,sizeof st);
    query(1,1,8001);

    map<int,int> mp;

    for(int i=0;i<maxn;i++){
        if(st[i]!=-1){
            mp[st[i]]++;

            int j=i;
            while(j<maxn&&st[j]==st[i]){
                j++;
            }
            i=j-1;
        }
    }
    for(auto x:mp){
        cout<<x.first<<' '<<x.second<<endl;
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(cin>>n){
        sol();
    }

    return 0;
}
