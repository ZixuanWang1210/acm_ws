#include<bits/stdc++.h>
#define LL long long
#define pa pair<int,int>
using namespace std;
struct Node{
	double x,y;
}dian[210];
double len(int p,int q){
	return sqrt((dian[p].x-dian[q].x)*(dian[p].x-dian[q].x)+(dian[p].y-dian[q].y)*(dian[p].y-dian[q].y));
}
int head[210],cnt;
int n,m;
struct Nod{
	int to,next;
	double w;
}edge[200000];
void add(int p,int q,double w){
	edge[cnt].to=q;
	edge[cnt].w=w;
	edge[cnt].next=head[p];
	head[p]=cnt++;
}
double dis[210];
bool vis[210];
int to[210];
struct di{
	double fi;
	int se;//fi边权
	bool operator < (const di &a)const {
		return fi > a.fi;         // 从小到大  ，fi小的优先级别高
	}
};
void dijkstra(int p,int q){//删除p--q的边 
	for(int i=1;i<=n;i++) dis[i]=2e9*1.0;
	memset(vis,false,sizeof(vis));
	priority_queue<di>qu;
	dis[1]=0.0;
	di n1;n1.se=1;n1.fi=0.0;
	qu.push(n1);
	while(!qu.empty()){
		di n2=qu.top();
		qu.pop();
		if(vis[n2.se]) continue;
		vis[n2.se]=true;
		for(int i=head[n2.se];~i;i=edge[i].next){
			int u=edge[i].to;
			if(u==q&&n2.se==p||n2.se==q&&u==p) continue;
			if(dis[u]>dis[n2.se]+edge[i].w){
				if(p==-1&&q==-1) to[u]=n2.se;
				dis[u]=dis[n2.se]+edge[i].w;
				di n3;n3.fi=dis[u];n3.se=u;
				qu.push(n3);
			}
		} 
	}
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&dian[i].x,&dian[i].y);
	int p,q;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p,&q);
		double l=len(p,q);
		add(p,q,l);
		add(q,p,l);
	}
	dijkstra(-1,-1);
	double ans=2e9*1.0;
	int now=n; //从后往前遍历 
	while(to[now]){
		dijkstra(now,to[now]);//删边一条边找最短路 
		ans=min(ans,dis[n]);
		now=to[now];
	}
    if(ans==2e9*1.0) printf("-1\n");
    else printf("%.2f\n",ans);
	return 0;
}
