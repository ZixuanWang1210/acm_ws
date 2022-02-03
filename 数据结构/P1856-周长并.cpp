#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define root tr[u]
#define rs tr[u<<1|1]
#define ls tr[u<<1]
using namespace std;

const int N=10005;
int n;
struct edge{
    int l,r,len; //len:区间总长度(竖着)(通过作差得到答案)
    int add,numx; //add:懒标记(区间被完全覆盖的次数),numx目前在维护几个线段(横着)
    bool lt,rt; //是否包含边界,合并用,详细见下
} tr[4*N];
struct node{
    int x,y1,y2;
    int v;
    bool operator<(node &t) const{
        if(x==t.x) return v>t.v; //先去边再加边(放置出现在y方向上并列出现的样例)
        else return x<t.x;
    }
} seg[2*N];

void build(int u,int l,int r){
    if(l==r){
        tr[u]={l,r,0,0,0,0,0};
        return;
    }  
    else{
        tr[u]={l,r,0,0,0,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        return;
    }
}

void pushup(int u){
    if(root.add){ //当前区间被覆盖了,他的长度就要统计,不论覆盖了几次,就算一次
        root.len=root.r-root.l+1; //维护信息的起源
        root.lt=root.rt=1;
        root.numx=1;
    }
    else if(root.l==root.r){ //维护区间信息不需要根节点
        root.lt=root.rt=0;
        root.len=0;
        root.numx=0;
    }
    else{
        root.len=ls.len+rs.len;
        root.lt=ls.lt;
        root.rt=rs.rt;
        root.numx=ls.numx+rs.numx-(ls.rt&rs.lt); //线段树维护的是连续的区间,如果同时覆盖了[1,2],[3,4],这种情况下,他们的(横边)是公用的,需要合并
    }
}

void modify(int u,int l,int r,int add){
    if(root.l>=l&&root.r<=r){
        root.add+=add;
        pushup(u);
    }
    else{
        int mid=root.r+root.l>>1; //debug了半天
        if(l<=mid) modify(u<<1,l,r,add);
        if(r>mid) modify(u<<1|1,l,r,add);
        pushup(u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int idx=0;
    int _max=-0x3f3f3f3f,_min=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        _min=min(_min,min(y1,y2)); _max=max(_max,max(y1,y2)); //线段树的l,r可以为负
        seg[++idx]={x1,y1,y2,1};
        seg[++idx]={x2,y1,y2,-1};
    }

    sort(seg+1,seg+idx+1);
    build(1,_min,_max-1); //用线段树维护区间时,长度是点数少一
    ll ans=0,last=0;

    for(int i=1;i<=idx;i++){
        modify(1,seg[i].y1,seg[i].y2-1,seg[i].v); //把每个边加入线段树,维护被覆盖的所有线段长
        ans+=abs(tr[1].len-last);
        ans+=(seg[i+1].x-seg[i].x)*2*tr[1].numx;
        last=tr[1].len;
    }

    cout<<ans;

    return 0;
}

/*

3
1 1 6 4
2 3 4 5
5 3 7 5 

2
0 0 4 4
0 4 4 8

*/