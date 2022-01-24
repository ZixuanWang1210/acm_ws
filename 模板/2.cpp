#include<bits/stdc++.h>
using namespace std;
#define int long long
int high,low,n,m;
struct node{
    int w;
    int id;
    int l;
    int lmt;
    friend bool operator < (const node& a, const node& b){
        return a.w < b.w;
    }
};
priority_queue<node>sd;
const int N=500050;
struct Sgt{
    int l,r;
    int cnt;
}sgt[N*40];
int sf[N];
int root[N];
int tot;
void mdf(int &now,int pre,int l,int r,int pos){
    sgt[now=++tot]=sgt[pre];
    sgt[now].cnt++;
    if(l==r)return;
    int mid=l+r>>1;
    if(pos>mid)mdf(sgt[now].r,sgt[pre].r,mid+1,r,pos);
    else mdf(sgt[now].l,sgt[pre].l,l,mid,pos);
}

int ask(int now,int pre,int l,int r,int k){
    if(l==r)return l;
    int mid=l+r>>1;
    if(sgt[sgt[now].r].cnt-sgt[sgt[pre].r].cnt>=k){
        return ask(sgt[now].r,sgt[pre].r,mid+1,r,k);
    } else {
        return ask(sgt[now].l,sgt[pre].l,l,mid,k-(sgt[sgt[now].r].cnt-sgt[sgt[pre].r].cnt));
    }
}
signed main(){
    cin>>n>>m>>low>>high;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i)a[i]+=a[i-1];
        sf[i+1]=a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int i=1;i<=n;i++){
        sf[i]=lower_bound(a.begin(),a.end(),sf[i])-a.begin()+1;
    }
    tot=1;
    for(int i=1;i<=n;i++){
        mdf(root[i],root[i-1],1,n,sf[i]);
    }
    for(int i=1;i<=n;i++){
        int r=min(n,i+high-1);
        int l=i+low-2;
        if(l>=n)break;
        int lmt=r-l;
        int tw=ask(root[r],root[l],1,n,1);
        int kw=0;
        if(i>1)kw=a[sf[i-1]-1];
        int rt=a[tw-1]-kw;
        sd.push({rt,1,i,lmt});
    }
    long long ans=0;
    while(m--){
        auto [w,id,l,lmt]=sd.top();
        sd.pop();
        // if(w<0)break;
        ans+=w;
        id++;
        if(id>lmt){
            continue;
        }
        int r=min(n,l+high-1);
        int l1=l+low-2;
        int k=ask(root[r],root[l1],1,n,id);
        int kw=0;
        if(l>1)kw=a[sf[l-1]-1];
        int rt=a[k-1]-kw;
        sd.push({rt,id,l,lmt});
    }
    cout<<ans<<"\n";
    return 0;
}