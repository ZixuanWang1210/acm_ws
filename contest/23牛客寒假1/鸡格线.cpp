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

int n,m;
const int maxn=5e5+10;
int a[maxn];
int cnt[maxn];

#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]


struct node{
    int l,r;
    int sum;
    bool flag;
} tr[maxn<<2];

void pushup(int u){
    root.sum=ls.sum+rs.sum;
    root.flag=ls.flag&rs.flag;
    return;
}

void build(int u,int l,int r){
    root={l,r,0,0};
    if(l==r){
        root.sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        if(root.flag) return;
        else{
            if(root.l==root.r){
                int kk=k;
                int re=-1;
                while(kk--){
                    if(root.sum==0||root.sum==99||root.sum==100){
                        root.flag=true;
                        return;
                    }
                    else root.sum=round(10*sqrt(root.sum));
                }
            }
            else{
                int mid=root.l+root.r>>1;
                if(l<=mid) modify(u<<1,l,r,k);
                if(r>mid) modify(u<<1|1,l,r,k);
                pushup(u);
            }
        }
    }
    else{
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while(m--){
        int op; cin>>op;
        if(op==1){
            int l,r,k; cin>>l>>r>>k;
            modify(1,l,r,k);
        }
        else cout<<tr[1].sum<<endl;
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
