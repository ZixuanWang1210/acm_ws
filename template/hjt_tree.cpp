#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;const int N=5*1e5+10;typedef long long ll;
int n;int k;int l;int r;int sum[N];ll res;int lsh[N];int rk[N];
int dl[N];int dr[N];
inline bool cmp(int a,int b){return sum[a]<sum[b];}//离散化 
struct data
{
	int rk;int l;int v;
	friend bool operator <(data a,data b){return a.v<b.v;} 
};priority_queue <data> pq;//保存答案的堆 
struct per_linetree//主席树板子，压行之后还是比较短小的 
{
	int s[25*N][2];int val[25*N];int root[N];int ct;int tim;
	per_linetree(){ct=root[0]=1;}
	inline void setadd(int p1,int p2,int l,int r,int pos)
	{
		val[p2]=val[p1]+1;if(r-l==1){return;}int mid=(l+r)/2;
		if(pos<=mid){s[p2][0]=++ct;s[p2][1]=s[p1][1];setadd(s[p1][0],ct,l,mid,pos);}
		else {s[p2][1]=++ct;s[p2][0]=s[p1][0];setadd(s[p1][1],ct,mid,r,pos);}
	}
	inline int kth(int p1,int p2,int l,int r,int rk)
	{
		if(r-l==1){return r;}int nv=val[s[p2][0]]-val[s[p1][0]];int mid=(l+r)/2;
		if(rk>nv){return kth(s[p1][1],s[p2][1],mid,r,rk-nv);}
		else {return kth(s[p1][0],s[p2][0],l,mid,rk);}
	}
	inline void cadd(int pos){setadd(root[tim],root[tim+1]=++ct,0,n,pos);tim++;}
	inline int ckth(int l,int r,int rk){return kth(root[l],root[r],0,n,rk);}
}plt;
int main()
{
	scanf("%d%d%d%d",&n,&k,&l,&r);
	for(int i=1;i<=n;i++){scanf("%d",&sum[i]);sum[i]+=sum[i-1];}//前缀和 
	for(int i=1;i<=n;i++){lsh[i]=i;}sort(lsh+1,lsh+n+1,cmp);//离散化 
	rk[lsh[1]]=1;for(int i=2;i<=n;i++){rk[lsh[i]]=(sum[lsh[i]]==sum[lsh[i-1]])?rk[lsh[i-1]]:i;}
	for(int i=1;i<=n;i++){plt.cadd(rk[i]);}
	dl[0]=l-1;dr[0]=r-1;//求出每个i对应的区间左右端点 
	for(int i=1;i<=n;i++)//插入的东西会比较恶心，凑合着看吧…… 
	{
		dl[i]=dl[i-1]+1;dr[i]=min(dr[i-1]+1,n);if(dl[i]>dr[i]){break;}
		pq.push((data){dr[i]-dl[i]+1,i,sum[lsh[plt.ckth(dl[i]-1,dr[i],dr[i]-dl[i]+1)]]-sum[i-1]});
	}
	for(int i=1;i<=k;i++)
	{
		data nw=pq.top();pq.pop();int v=nw.l;res+=nw.v; 
		if(nw.rk==1){continue;}//判一下是不是最小值 
		pq.push((data){nw.rk-1,v,sum[lsh[plt.ckth(dl[v]-1,dr[v],nw.rk-1)]]-sum[v-1]});//不是最小值就接着插入 
	}printf("%lld",res);return 0;//拜拜程序~ 
}