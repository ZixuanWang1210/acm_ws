
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e4+10,M=5*N,inf=1ll<<60;
int f[N],n,m,u,t,s;
int nxt[M],head[N],go[M],w[M],tot;
void add(int &u,int &v,int &o){
	nxt[++tot]=head[u],head[u]=tot,go[tot]=v,w[tot]=o;
	nxt[++tot]=head[v],head[v]=tot,go[tot]=u,w[tot]=o;
}
int dis[N];
struct node{
	int x,d;
	bool operator<(const node&rch)const{
		return d>rch.d;
	}
};
priority_queue<node>q;
inline bool spfa(int mid){
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[u]=0; q.push((node){u,0});
	while(q.size()){
		int x=q.top().x,d=q.top().d;
		q.pop();
		if(d!=dis[x])continue;
		for(int i=head[x];i;i=nxt[i]){
			int v=go[i],y=w[i];
			if(f[v]>mid)continue;
			if(dis[v]>dis[x]+y){
				dis[v]=dis[x]+y;
				q.push((node){v,dis[v]});
			}
		}
	}
	if(dis[t]<=s)return 1;
	else return 0;
}
signed main(){
	cin>>n>>m>>u>>t>>s;int l=0,r=0,ans=-1;
	for(int i=1;i<=n;i++)scanf("%lld",&f[i]),r=max(r,f[i]+1); l=max(f[u],f[t]);
	for(int i=1,a,b,c;i<=m;i++)scanf("%lld%lld%lld",&a,&b,&c),add(a,b,c);
	while(l<=r){
		int mid=(l+r)>>1;
		if(spfa(mid)){
			r=mid-1;
			ans=mid;
		}
		else
		l=mid+1;
	}
	cout<<ans<<endl;
}