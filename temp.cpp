#include <cstdio>
#define Len(i) (tr[i].r-tr[i].l+1)
const int MAXN = 100005;
#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]
int read()
{
    int x=0,flag=1;char c;
    while((c=getchar())<'0' || c>'9') if(c=='-') flag=-1;
    while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return x*flag;
}
int n,m,q,ans,a[MAXN];
struct node
{
    int op,l,r;
}s[MAXN];
struct tree
{
    int l,r,sum,lazy;
}tr[MAXN*4];
void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r){
        tr[u]={l,r,0,0};
        return;
    }
    else{
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        return;
    }
}

void down(int u){
    if(root.lazy==1){
        ls.sum=(ls.r-ls.l+1),ls.lazy=1;
        rs.sum=(rs.r-rs.l+1),rs.lazy=1;
    }
    else{
        ls.sum=0,ls.lazy=2;
        rs.sum=0,rs.lazy=2;
    }
    root.lazy=0;
}
void updata(int i,int l,int r,int t)
{
    if(l>r || tr[i].l>r || tr[i].r<l)
        return ;
    if(l<=tr[i].l && tr[i].r<=r)
    {
        if(t==0) tr[i].sum=Len(i),tr[i].lazy=1;
        else tr[i].sum=0,tr[i].lazy=2;
        return ;
    }
    if(tr[i].lazy) down(i);
    updata(i<<1,l,r,t);
    updata(i<<1|1,l,r,t);
    tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
}
int query(int u,int l,int r){
    if(l<=root.l&&r>=root.r){
        return root.sum;
    }
    else{
        if(root.lazy) down(u);
        int mid=root.l+root.r>>1,ans=0;
        if(l<=mid) ans+=query(u<<1,l,r);
        if(r>mid) ans+=query(u<<1|1,l,r);
        return ans;
    }
}
bool check(int x)
{
    build(1,1,n);
    for(int i=1;i<=n;i++)
        updata(1,i,i,a[i]>=x);
    for(int i=1;i<=m;i++)
    {
        int op=s[i].op,l=s[i].l,r=s[i].r;
        int t=query(1,l,r);
        if(op==0)
        {
            updata(1,l,l+t-1,0);
            updata(1,l+t,r,1);
        }
        else
        {
            updata(1,l,r-t,1);
            updata(1,r-t+1,r,0);
        }
    }
    return query(1,q,q)==0;
}
void dich(int l,int r)
{
    if(l>r) return ;
    int mid=(l+r)>>1;
    if(check(mid))
    {
        ans=mid;
        dich(mid+1,r);
    }
    else
        dich(l,mid-1);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=m;i++)
        s[i]=node{read(),read(),read()};
    q=read();
    dich(1,n);
    printf("%d\n",ans);
}
