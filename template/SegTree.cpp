#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=;
struct node{
    int l,r;
    int lazy;
} tr[maxn<<2];

#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
}

void pushdown(int u){
    if(root.lazy){
    }
}

void build(int u,int l,int r){
    if(l==r) root=;
    else{
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){

    }
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=root.l&&r>=root.r) return root.sum;
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        int sum=0;
        if(l<=mid) sum+=query(u<<1,l,r);
        if(r>mid) sum+=query(u<<1|1,l,r);
        return sum;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    return 0;
}
